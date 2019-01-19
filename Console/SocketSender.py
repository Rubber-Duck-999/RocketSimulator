import socket
import sys
from _socket import SHUT_RDWR


class SocketSender:
    # Main Class
    
    def __init__(self, Host, Port, listenTime):
        # Constructor of Sockets Class
        self.Host = Host
        self.Port = Port
        # Set up of the variables for Host and port on the socket
        # Needs to be configured for each user
        self.listenTime = listenTime
        self.byteSize = 1024
        self.encoding = 'UTF-8'
        self.minDataID = 101
        self.maxDataID = 105
        self.loopValueMain = True
        self.acknowledged = False
        
    def sendAckMessages(self, sendDataID, sendDataPackage):
        if not self.acknowledged:
            self.sendData = str(sendDataID) + '_' + str(sendDataPackage)
            # Add ID to the data being sent with package data
            self.sendDataString = str(self.sendData)
            # Convert value to string format
            self.sendDataString = "M_" + self.sendDataString + "\n";
            # Format for message type
            self.sendData = self.sendDataString.encode()
            # The encoding default here is strict
            self.conn.send(self.sendData)
            print("We sent: " + self.sendDataString)
        # Fix message with M character prefix              
        self.data = self.conn.recv(self.byteSize)
        # Receive 1024 bytes
        self.line = self.data.decode(self.encoding)   
        # convert to string
        self.replaceLine = self.line.replace("\n", "")   
        # remove newline character
        if "ACK_" in self.line:
            print("We received: " + self.line)
            self.acknowledged = True
            self.allowSend = False
            self.loopValueMain = False
        else:
            print("Message has not been acknowledged")
            self.acknowledged = False
            

    def set_sendDataID(self, sendDataID):
        self.sendDataID = sendDataID

    def set_sendDataPackage(self, sendDataPackage):
        self.sendDataPackage = sendDataPackage 
            
    def validateData(self):
        if self.minDataID <= self.sendDataID <= self.maxDataID:
            print("ID is in the bounds, set currently at: " + str(self.sendDataID))
            self.allowSend = True
        else:
            print("ID is out of the bounds, set currently at: " + str(self.sendDataID))
            self.allowSend = False
    
    def run(self):
        # Variable for main loop
        print("Program Startup")
        while self.loopValueMain:
            # Loop Value Variable set to True at start up
            self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            # Create socket on port
            try:
                # Try block checks if there is a socket error
                self.s.bind((self.Host, self.Port))
            except socket.error:
                print('# Bind failed. ')
                sys.exit()
            print('# Socket bind complete')
            self.allowSend = True
            try:
                self.s.listen(self.listenTime)
                print('# Socket now listening')
                self.conn, self.addr = self.s.accept()
            # Exception if socket.error occurs
            # Binding of the socket
            except BrokenPipeError:
                self.allowSend = False
                # If broken pipe error appears then exit the loop in this member function
                print("Waiting for pipe reconnection")
            print('# Connected to Host' + self.addr[0] + ' On port:' + str(self.addr[1]))
            # Host and Port print out
            self.validateData()
            while self.allowSend:
                self.sendAckMessages(self.sendDataID, self.sendDataPackage)
                # Set up send of messages over Socket in a endless loop
        
    def close(self):
        self.loopValueMain = False
        self.conn.close()
        self.s.close()
        # Shutdowns all socket activities