import socket
import sys

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ('localhost', 8120)
message = 'CONNECT 4'

try:

    # Send data
    print >>sys.stderr, 'sending "%s"' % message
    sent = sock.sendto(message, server_address)
	
finally:
    print >>sys.stderr, 'closing socket'
    sock.close()
	
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = ('127.0.0.1', 8120)
try:
	# Receive response
	while(True):
		print >>sys.stderr, 'waiting to receive'
		data, server = sock.recv(4096)
		print >>sys.stderr, 'received "%s"' % data

finally:
    print >>sys.stderr, 'closing socket'
    sock.close()