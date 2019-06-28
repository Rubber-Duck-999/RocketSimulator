'''
Created on 18 Jan 2019

@author: simon
'''

from enum import Enum

class Pilots(Enum):
    BOB   = 0
    FRED  = 1
    RYAN  = 2
    SARAH = 3
    GRACE = 4 

class dataStructure:
    def getDataStructure(self):
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
        self.dataStructure =  ('-Mass:' + str(self.mass) + '-DragX:' + str(self.dragAxisX) + '-DragY:' + str(self.dragAxisY) +
                               '-Hori:' + str(self.horiCrossSectArea) + '-Vert:' + str(self.vertCrossSectArea) +
                               '-Thrust:' + str(self.thrust) + '-BurnTime:' + str(self.burnTime) + 
                               '-Flowrate:' + str(self.flowRate) + '-LaunchAngle:' + str(self.angleOfLaunch))
        
class launcherMissionParameters(dataStructure):
    def __init__(self, ID, pilot,
                 timeToLaunchSec):
        self.ID = ID
        self.pilot = pilot 
        self.timeToLaunchSec = timeToLaunchSec
        self.dataStructure =  ('-Pilot:' + str(self.pilot) +
                               '-Sec:' + str(self.timeToLaunchSec))

class terrainDataParameters(dataStructure):
    def __init__(self, ID, density, gravity):
        self.ID = ID
        self.density = density
        self.gravity = gravity
        self.dataStructure = ('-Density:' + str(self.density) + '-Gravity:' + str(self.gravity))
    



