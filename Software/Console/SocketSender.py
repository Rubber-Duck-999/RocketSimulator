import socket, sys, time, types

MAX_TIMEOUT = 2.00
MIN_TIMEOUT = 0.05

class SocketSender:
    # Main Class
    
    def __init__(self, Host, Port):
        # Constructor of Sockets Class
        self.Host = Host
        self.Port = Port
        # Set up of the variables for Host and port on the socket
        # Needs to be configured for each user
        self.byteSize = 1024
        self.encoding = 'UTF-8'
        self.dataTypeValid = False
        self.timeout = 0.50
        
    def setTimeout(self, timeout):
        if timeout < MAX_TIMEOUT and timeout > MIN_TIMEOUT:
            self.timeout = timeout

    def setDataPackage(self, dataPackage):
        MAX_LENGTH = 100
        MIN_LENGTH = 2
        length = len(dataPackage)
        if isinstance(dataPackage, list):
            length = len(dataPackage)
            if length >= MIN_LENGTH and length <= MAX_LENGTH:
                self.dataPackage   = dataPackage
                self.dataTypeValid = True
            else:
                self.dataPackage = "EMPTY"
                self.dataTypeValid = False
        return self.dataTypeValid
        
    def sendAckMessages(self):
        if not self.acknowledged:
            self.sendDataString = str(self.dataPackage)
            # Add ID to the data being sent with package data
            self.sendDataString = "M_" + self.sendDataString + "\n";
            # Format for message type 
            self.sendData = self.sendDataString.encode()
            # The encoding default here is strict
            self.s.sendto(self.sendData, (self.Host, self.Port))
            print("We sent: " + self.sendDataString)
            print("We sent to: " + self.Host + ".")
            print("We sent to: " + str(self.Port))
        # Fix message with M character prefix
        try:
            self.data = self.s.recv(self.byteSize)
            #self.data = self.data[0]
            self.line = self.data.decode(self.encoding)   
            # convert to string
            self.replaceLine = self.line.replace("\n", "")   
            # remove newline character
            # Receive 1024 bytes
            if "ACK_" in self.line:
                print("We received: " + self.line)
                self.acknowledged = True
            else:
                print("Message has not been acknowledged")
                self.acknowledged = False            
        except socket.error:
            return False
            
    
    def connect(self):
        # Variable for main loop
        if self.dataTypeValid:
            self.acknowledged  = False
            try:
                self.s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                self.s.settimeout(self.timeout)
            except socket.error:
                print('Failed to create socket')
                return
            self.sends = 0
            while not self.acknowledged and self.sends < 4:
                self.sendAckMessages()
                self.sends = self.sends + 1
                # Set up send of messages over Socket in a endless loop
            return self.acknowledged
        else:
            return False
        
    def close(self):
        self.s.close()
        # Shutdowns all socket activities
        
        