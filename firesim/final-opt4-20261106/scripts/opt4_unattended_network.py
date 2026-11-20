#!/usr/bin/env python3
"""Local CONNECT transport for the existing model provider only.

TLS remains end-to-end, including the CLI's certificate/name verification.
This process has no credential access, no hardware access and no general proxy.
The initial TLS record is sent in small TCP writes for this network path.
"""
import select
import socket
import socketserver
import time

HOST='beeapi.ai'
IPS=['172.67.156.141','104.21.7.249']

def exact(s,n):
    b=b''
    while len(b)<n:
        x=s.recv(n-len(b))
        if not x:raise ConnectionError('short TLS initial record')
        b+=x
    return b

class Handler(socketserver.BaseRequestHandler):
    def handle(self):
        upstream=None
        try:
            c=self.request;c.settimeout(15)
            request=b''
            while b'\r\n\r\n' not in request and len(request)<8192:
                request+=exact(c,1)
            if request.split(b'\r\n',1)[0]!=b'CONNECT beeapi.ai:443 HTTP/1.1':
                c.sendall(b'HTTP/1.1 403 Forbidden\r\nContent-Length: 0\r\n\r\n');return
            for ip in IPS:
                try:upstream=socket.create_connection((ip,443),timeout=8);break
                except OSError:pass
            if upstream is None:raise ConnectionError('upstream unavailable')
            c.sendall(b'HTTP/1.1 200 Connection established\r\n\r\n')
            h=exact(c,5);n=int.from_bytes(h[3:5],'big');assert h[0]==22 and 0<n<32768
            hello=exact(c,n)
            upstream.setsockopt(socket.IPPROTO_TCP,socket.TCP_NODELAY,1)
            for i in range(0,len(hello),32):
                part=hello[i:i+32]
                upstream.sendall(h[:3]+len(part).to_bytes(2,'big')+part);time.sleep(.004)
            c.setblocking(False);upstream.setblocking(False)
            deadline=time.monotonic()+3600
            while time.monotonic()<deadline:
                ready,_,_=select.select([c,upstream],[],[],30)
                for src in ready:
                    data=src.recv(65536)
                    if not data:return
                    dst=upstream if src is c else c
                    dst.settimeout(30);dst.sendall(data);dst.setblocking(False)
                    deadline=time.monotonic()+3600
        except (OSError,ValueError,AssertionError,ConnectionError):pass
        finally:
            if upstream:upstream.close()

class Server(socketserver.ThreadingTCPServer):
    allow_reuse_address=True
    daemon_threads=True

if __name__=='__main__':
    Server(('127.0.0.1',2732),Handler).serve_forever()
