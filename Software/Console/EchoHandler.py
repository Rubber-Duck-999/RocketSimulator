import socket
import sys

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ('localhost', 20000)
message = 'CONNECT 1'

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)	
server_address = ('localhost', 20000)
try:
	# Receive response
	while(True):
		print >>sys.stderr, 'waiting to receive'
		data, server = sock.recv(4096)
		print >>sys.stderr, 'received "%s"' % data

finally:
    print >>sys.stderr, 'closing socket'
    sock.close()