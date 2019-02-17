'''
Created on 18 Jan 2019

@author: simon
'''

from SocketSender import SocketSender 
from enum import Enum
import enum


class Pilots(Enum):
    FRED  = 1
    RYAN  = 2
    SARAH = 3
    GRACE = 4


class State(Enum):
    NON_CONFIGURED = 0
    CONFIGURED     = 1
    READY          = 2
    LAUNCH         = 3
    RETURN         = 4
    SHUTDOWN       = 5 


dataStructureTerrain = { 'ID' : 101,
                         'density' : 0.0,
                         'accelerationDueToGravity' : 0.0 }


dataStructureLauncher = { 'ID' : 102,
                          'pilots' : Pilots.FRED,
                          'timeToLaunchMin' : 0,
                          'timeToLaunchSec' : 0 }

dataStructureState = { 'ID' : 103,
                       'currentState' : State.NON_CONFIGURED }
        
dataStructurRocket = { 'ID' : 104,
                        'mass' : 0.0,
                        'dragAxisX' : 0.0,
                        'dragAxisY' : 0.0,
                        'horiCrosSectArea' : 0.0,
                        'vertCrossSectArea' : 0.0,
                        'thrust' : 0.0,
                        'burnTime' : 0.0,
                        'flowRate' : 0.0,
                        'angleOfLaunch' : 0.0}

class dataStructureRocket():
        
    def _init_(self, ID, mass, dragAxisX, dragAxisY, 
               horiCrossSectArea, vertCrossSectArea,
               thrust, burnTime, flowRate, 
               angleOfLaunch):
        
        

def sendData(dataStructure):
    Socket = SocketSender("", 20000, 10)
    ID = dataStructure['ID'] 
    print(str(ID))
    Socket.set_sendDataID(ID)
    Socket.set_sendDataPackage(dataStructure)
    Socket.run()
    Socket.close()
 
    
#sendData(dataStructureTerrain)   
#sendData(dataStructureLauncher)
#sendData(dataStructureState)
#sendData(dataStructureRocket)
