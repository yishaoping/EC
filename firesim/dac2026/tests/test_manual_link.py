"""Host-only output checker tests; never execute a guest/benchmark or script."""
from pathlib import Path
import subprocess
import tempfile
import unittest


class ManualOutputValidation(unittest.TestCase):
    def check_output(self, text, reference=None):
        script = (Path(__file__).parents[1]/'guest/manual-link.sh').read_text()
        awk = script.split("/bin/busybox awk '", 1)[1].split("\n  ' \"$input\"", 1)[0]
        with tempfile.TemporaryDirectory() as directory:
            inp = Path(directory)/'input'
            out = Path(directory)/'prices'
            inp.write_text(reference or '2\n42 40 0.1 0 0.2 0.5 C 0 4.759423\n42 40 0.1 0 0.2 0.5 P 0 0.808600\n')
            out.write_text(text)
            return subprocess.run(['/usr/bin/awk', awk, str(inp), str(out)],
                                  capture_output=True, text=True).returncode

    def test_accepts_reference_within_bound(self):
        self.assertEqual(self.check_output('2\n4.759423\n0.808600\n'), 0)
        self.assertEqual(self.check_output('2\n4.759433\n0.808590\n'), 0)

    def test_rejects_incomplete_nonfinite_wrong_or_extra_output(self):
        for bad in ['', '2\n4.759423\n', '2\n4.759423\n0.808600\n0\n',
                    '3\n4.759423\n0.808600\n', '2\n4.760423\n0.808600\n',
                    '2\nnan\n0.808600\n', '2\ninf\n0.808600\n',
                    '2\n1e999\n0.808600\n', '2\n4.759423 garbage\n0.808600\n']:
            with self.subTest(output=bad):
                self.assertNotEqual(self.check_output(bad), 0)


if __name__ == '__main__':
    unittest.main()
