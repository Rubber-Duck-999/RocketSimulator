'''
Created on 18 Jan 2019

@author: simon
'''

from SocketSender import SocketSender 
from enum import Enum

Port = 6111


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

class dataStructure:
    def setID(self, ID):
        self.ID = ID
        
    def send(self):
        return self.dataStructure


class rocketDataParameters(dataStructure): 
    def __init__(self, ID, mass, dragAxisX, dragAxisY, 
               horiCrossSectArea, vertCrossSectArea,
               thrust, burnTime, flowRate, 
               angleOfLaunch):
        self.ID = ID
        self.mass = mass
        self.dragAxisX = dragAxisX
        self.dragAxisY = dragAxisY
        self.horiCrossSectArea = horiCrossSectArea
        self.vertCrossSectArea = vertCrossSectArea
        self.thrust = thrust
        self.burnTime = burnTime
        self.flowRate = flowRate
        self.angleOfLaunch = angleOfLaunch
        self.dataStructure = [ self.ID, self.mass, self.dragAxisX, self.dragAxisY,
                               self.horiCrossSectArea, self.vertCrossSectArea,
                               self.thrust, self.burnTime, self.flowRate,
                               self.angleOfLaunch ]  
        
class launcherMissionParameters(dataStructure):
    def __init__(self, ID, pilot,
                 timeToLaunchMin,
                 timeToLaunchSec):
        self.ID = ID
        self.pilot = pilot 
        self.timeToLaunchMin = timeToLaunchMin
        self.timeToLaunchSec = timeToLaunchSec
        self.dataStructure = [ self.ID, self.pilot,
                               self.timeToLaunchMin,
                               self.timeToLaunchSec ]
        
class stateDataParameters(dataStructure):
    def __init__(self, ID, currentState):
        self.ID = ID
        self.currentState = currentState
        self.dataStructure = [ self.ID, self.currentState ]       

class terrainDataParameters(dataStructure):
    def __init__(self, ID, density, gravity):
        self.ID = ID
        self.density = density
        self.gravity = gravity
        self.dataStructure = [ self.ID, self.density, self.gravity ]


def sendStateData(Data):
    Socket = SocketSender("", Port, 10)
    Socket.set_sendDataPackage(Data)
    Socket.run()
    Socket.close()

def sendAllData(state, terrain, launcher, rocket, runSwitch):
    Socket = SocketSender("", Port, 10)
    data = state + terrain + launcher + rocket
    Socket.set_sendDataPackage(data)
    Socket.run()
    Socket.close()
    



