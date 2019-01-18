'''
Created on 17 Jan 2019

@author: simon
'''
from socketserver import BaseRequestHandler, TCPServer, StreamRequestHandler

class EchoHandler(BaseRequestHandler):
    '''
    classdocs
    '''
    def handle(self):
        print('Got connection from', self.client_address)
        x = True
        while x:
            msg = self.request.recv(8192)
            if not msg:
                break
            print(msg)
            self.request.send(msg)
            

if __name__ == '__main__':
    serv = TCPServer(('', 20000), EchoHandler)
    serv.serve_forever()