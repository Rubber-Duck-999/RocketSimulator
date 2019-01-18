'''
Created on 18 Jan 2019

@author: simon
'''

from SocketSender import SocketSender

dataStructureTerrain = { 'ID' : 101,
                         'density' : 0.0,
                         'accelerationDueToGravity' : 0.0 }

class TerrainMissionParametersSocketSender(SocketSender):
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
        self.IDvalid = False
        
    def validateID(self, sendDataID):
        if sendDataID in dataStructureTerrain.keys():
            return True
        else:
            return False
        
    def validatePackage(self, sendDataPackage):
        if sendDataPackage in dataStructureTerrain.keys():
            return True
        else:
            return False