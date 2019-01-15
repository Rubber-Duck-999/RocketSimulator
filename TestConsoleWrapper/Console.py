#! usr/bin/pyhton3

import socket
import sys
import random


class Sockets:
   #Main Class
   
   def __init__(self):
       # Constructor of Sockets Class
       self.Host = ''
       self.Port = 61377
       # Set up of the variables for Host and port on the socket
       # Needs to be configured for each user
       self.listenTime = 10
       
   def sendMessages(self):
       self.readLoopValue = True;
       # Loop Value Variable set to True at start up
       self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
       # Create socket on port
       try:
          # Try block checks if there is a socket error
          self.s.bind((self.Host, self.Port))
       except socket.error as msg:
          print('# Bind failed. ')
          sys.exit()
          # Exception if socket.error occurs
       while self.readLoopValue:
           try:
              print('# Socket bind complete')
              self.s.listen(self.listenTime)
              print('# Socket now listening')
              self.conn, self.addr = self.s.accept()
              # Binding of the socket
              print('# Connected to Host' + self.addr[0] + ' On port:' + str(self.addr[1]))
              # Host and Port print out
              while True:  
                  self.sendData = random.randint(0,100)
                  # Set data as a number between 0 and 100 to identify that 
                  # print( self.sendData )
                  self.sendDataString = str(self.sendData)
                  self.sendDataString = "M" + self.sendDataString + "\n"
                  self.conn.send(self.sendDataString)
                  # Fix message with M character prefix			  
                  self.data = self.conn.recv(1024)
                  # Receive 1024 bytes
                  self.line = self.data.decode('UTF-8')   
                  # convert to string
                  self.line = self.line.replace("\n","")   
                  # remove newline character
                  print( self.line )
           except BrokenPipeError:
              self.readLoopValue = False
              # If broken pipe error appears then exit the loop in this member function
           print("Waiting for pipe reconnection")
  
   def run(self):
       self.loopValueMain = True
       # Variable for main loop
       print("Program Startup")
       while self.loopValueMain:
           self.sendMessages()
           # Set up send of messages over Socket in a endless loop
           
   def close(self):
       self.conn.close()
       self.s.shutdown()
       self.s.close()
       # Shutdowns all socket activities
       
mySocket = Sockets()
mySocket.run()
mySocket.close()


