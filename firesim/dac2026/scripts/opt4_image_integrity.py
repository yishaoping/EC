"""Verify application bytes in the exact native initramfs before RTL boot."""
import hashlib
from pathlib import Path


def attest(rootfs, apps, apps_receipt_sha):
    expected = rootfs.get('image_application_files')
    if not expected:
        raise ValueError('native HTIF requires a complete image application inventory')
    found = {}
    with Path(rootfs['initramfs']).open('rb') as stream:
        while True:
            header = stream.read(110)
            if len(header) != 110 or header[:6] != b'070701':
                raise ValueError('invalid newc initramfs')
            fields = [int(header[i:i+8], 16) for i in range(6, 110, 8)]
            size, namesize = fields[6], fields[11]
            if not 0 < namesize < 4096 or size > 128 * 1024 * 1024:
                raise ValueError('invalid newc entry size')
            encoded = stream.read(namesize)
            if len(encoded) != namesize or encoded[-1:] != b'\0':
                raise ValueError('invalid newc filename')
            name = encoded[:-1].decode()
            stream.read((-(110+namesize)) % 4)
            data = stream.read(size)
            if len(data) != size:
                raise ValueError('truncated initramfs')
            stream.read((-size) % 4)
            if name == 'TRAILER!!!':
                break
            name = name.removeprefix('./')
            if name.startswith('opt/ec-dac/'):
                if name in found or fields[1] & 0o170000 != 0o100000:
                    # The directory itself has no trailing slash; every
                    # application child in this profile is a regular file.
                    if fields[1] & 0o170000 == 0o040000:
                        continue
                    raise ValueError('duplicate/nonregular application image entry: '+name)
                found[name] = hashlib.sha256(data).hexdigest()
    if found != expected:
        raise ValueError('application bytes in initramfs differ from the build inventory')
    required = {'opt/ec-dac/'+name: digest for name, digest in apps['binaries'].items()}
    for mode, description in apps['inputs'].items():
        required.update({'opt/ec-dac/inputs/'+mode+'/'+name: digest
                         for name, digest in description['files'].items()})
    required['opt/ec-dac/BUILD.json'] = apps_receipt_sha
    if any(found.get(name) != digest for name, digest in required.items()):
        raise ValueError('initramfs application/input/BUILD versions do not match the software receipts')
    return {'verified': True, 'method': 'SHA256 of actual newc entry bytes before RTL execution',
            'files': found, 'required_versions': required,
            'input_still_hashed_in_guest': True}
