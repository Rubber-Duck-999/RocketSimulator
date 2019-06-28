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
        self.currentMessage = "NULL"
        self.acknowledged = False
        
    def setTimeout(self, timeout):
        if timeout < MAX_TIMEOUT and timeout > MIN_TIMEOUT:
            self.timeout = timeout

    def setDataPackage(self, dataPackage):
        MAX_LENGTH = 200
        MIN_LENGTH = 2
        length = len(dataPackage)
        if isinstance(dataPackage, str):
            length = len(dataPackage)
            if length >= MIN_LENGTH and length <= MAX_LENGTH:
                self.dataPackage   = dataPackage
                self.dataTypeValid = True
                self.acknowledged = False
            else:
                self.dataPackage = "EMPTY"
                self.dataTypeValid = False
        return self.dataTypeValid
        
    def receiveMessage(self):
        try:
            self.data = self.s.recv(self.byteSize)
            #self.data = self.data[0]
            self.line = self.data.decode(self.encoding)   
            # convert to string
            self.replaceLine = self.line.replace("\n", "")   
            # remove newline character
            # Receive 1024 bytes
            if "ID:" in self.line:
                print("We received: " + self.line)
                self.acknowledged = True
                self.currentMessage = self.replaceLine
            else:
                print("Message has not been acknowledged")
                self.acknowledged = False            
        except socket.error:
            return  
            
    def sendMessages(self):
        if not self.acknowledged:
            self.sendDataString = str(self.dataPackage)
            # Add ID to the data being sent with package data
            self.sendDataString = self.sendDataString + "\n";
            # Format for message type 
            self.sendData = self.sendDataString.encode()
            # The encoding default here is strict
            self.s.sendto(self.sendData, (self.Host, self.Port))
            print("We sent: " + self.sendDataString)
            print("We sent to: " + self.Host + ".")
            print("We sent to: " + str(self.Port))
            self.receiveMessage()
            time.sleep(0.5)
            
    
    def connect(self):
        # Variable for main loop
        try:
            self.s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            self.s.settimeout(self.timeout)
            return True
        except socket.error:
            print('Failed to create socket')
            return False
        
    def close(self):
        self.s.close()
        # Shutdowns all socket activities
        
        