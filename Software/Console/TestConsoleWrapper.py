# ! usr/bin/pyhton3

import socket
import sys


class TestSockets:
    # Main Class
   
    def __init__(self, Host, Port, listenTime):
        # Constructor of Sockets Class
        self.Host = Host
        self.Port = Port
        # Set up of the variables for Host and port on the socket
        # Needs to be configured for each user
        self.listenTime = listenTime
       
    def sendAckMessages(self, sendData):
        self.readLoopValue = True;
        # Loop Value Variable set to True at start up
        self.s = socket.socket()
        # Create socket on port
        self.send = False
        try:
           # Try block checks if there is a socket error
           self.s.connect((self.Host, self.Port))
        except socket.error as msg:
           print('# Bind failed. ')
           sys.exit()
           # Exception if socket.error occurs
        while self.readLoopValue:
            try:
               print('# Socket bind complete')
               # Fix message with M character prefix			  
               self.data = self.s.recv(1024)
               # Receive 1024 bytes
               self.line = self.data.decode('UTF-8')   
               # convert to string
               self.replaceLine = self.line.replace("\n", "")
               if "M_" in self.line:
                   print("We received ID 101: " + self.line)
                   self.send = True
               if self.send:
                   self.sendDataString = str(sendData)
                   self.sendDataString = self.sendDataString + self.line + "\n"
                   self.sendData = self.sendDataString.encode()
                   self.s.send(self.sendData)
                   print("We sent: " + self.sendDataString)
                   self.sendMessage = False
                   self.readLoopValue = False
            except BrokenPipeError:
               self.readLoopValue = False
               # If broken pipe error appears then exit the loop in this member function
            print("Waiting for pipe reconnection")
  
    def run(self):
        self.loopValueMain = True
        # Variable for main loop
        print("Program Startup")
        sendData = "ACK_"
        while self.loopValueMain:
            self.sendAckMessages(sendData)
            # Set up send of messages over Socket in a endless loop
           
    def close(self):
        self.s.close()
        # Shutdowns all socket activities

       
mySocket = TestSockets("localhost", 6111, 10)
mySocket.run()
mySocket.close()
