'''
Created on 19 Jan 2019

@author: simon
'''

import sys, queue, threading, time
from ConsoleDataStructure import *
from PySimpleGUI.PySimpleGUI import Popup
if sys.version_info[0] >= 3:
    import PySimpleGUI as sg


class GUI(threading.Thread):
    def __init__(self, queue):
        threading.Thread.__init__(self)
        self.queue = queue
        self.buttonBack = 'Reset Values to Default'
        self.buttonNext = 'Next Page'
        self.resetValues()
        
    def resetValues(self):    
        self.defaultPilot     = Pilots.FRED
        self.defaultGravity   = 9.87
        self.defaultDensity   = 0.00
        self.defaultMass      = 0.00
        self.defaultThrust    = 0.00
        self.defaultDragAxisX = 0.00
        self.defaultDragAxisY = 0.00
        self.defaultHoriCross = 0.00
        self.defaultVertCross = 0.00
        self.defaultBurnTime  = 0.00
        self.defaultFlowRate  = 0.00
        self.defaultAngle     = 90.00
        self.dataStructure    = [ self.defaultGravity, self.defaultDensity, self.defaultMass,      
                                  self.defaultThrust, self.defaultDragAxisX, self.defaultDragAxisY, 
                                  self.defaultHoriCross, self.defaultVertCross, self.defaultBurnTime,  
                                  self.defaultFlowRate, self.defaultAngle ]
        self.colour    = 'Dark'
        self.messageID = 101 
        self.dataReady = False     
        self.State = State.NON_CONFIGURED
        self.defaultTimeToLaunchMin = 0.00
        self.defaultTimeToLaunchSec = 0.00
                      
    def Validate(self, value, MIN, MAX):
        if value < MIN or value > MAX:
            return False
        else:
            return True
        
    def ValidateEntries(self):
        MIN = 0.00
        output = True
        for name in self.dataStructure:
            if not self.Validate(name, MIN, 300.0):
                output = False
        return output  
    
    def assignUIEntries(self, entries):
        self.defaultPilot = entries.get('pilots')
        i = 0
        print("Assigning UI Values")
        for name in self.dataStructure:
            name = float(entries.get(i))
            self.dataStructure[i] = name
            i = i + 1   
        print(self.dataStructure)
          
    def MainUI(self):
        print("Entering Main Screen")
        self.State = State.NON_CONFIGURED
        sg.ChangeLookAndFeel(self.colour)
        layout = [
            [sg.Text('Welcome to the Rocket Simulator Console (2D)', size=(40, 1), font=("Helvetica", 25))],
            [sg.Text('Please enter the data from the mission to begin')],
            [sg.Text('Pick which pilot to use:'),
             sg.InputCombo((Pilots.FRED, Pilots.RYAN, Pilots.SARAH, Pilots.GRACE), key='pilots', size=(20, 1))],
            
            [sg.Text('Enter the Planet Terrain Details:', font=("Helvetica", 15))],
            [sg.Text('Acceleration due to Gravity (Max 10)', 
                     size=(35, 1)), sg.InputText(self.defaultGravity)],
            [sg.Text('Define the density of the planets atmosphere:', 
                     size=(35, 1)), sg.InputText(self.defaultDensity)],
            [sg.Text('Enter the Rocket Details:', font=("Helvetica", 15))],
            [sg.Text('Mass (KG)', 
                     size=(35, 1)), sg.InputText(self.defaultMass)],
            [sg.Text('Thrust (N)',
                     size=(35, 1)), sg.InputText(self.defaultThrust)],
            [sg.Text('Drag Coefficient on the X Axis', 
                     size=(35, 1)), sg.InputText(self.defaultDragAxisX)],
            [sg.Text('Drag Coefficient on the Y Axis', 
                     size=(35, 1)), sg.InputText(self.defaultDragAxisY)],
            [sg.Text('Horizontal Cross Sectional Area', 
                     size=(35, 1)), sg.InputText(self.defaultHoriCross)],
            [sg.Text('Vertical Cross Sectional Area', 
                     size=(35, 1)), sg.InputText(self.defaultVertCross)],
            [sg.Text('Burn Time', 
                     size=(35, 1)), sg.InputText(self.defaultBurnTime)],
            [sg.Text('Flow Rate of the Fuel', 
                     size=(35, 1)), sg.InputText(self.defaultFlowRate)],
            [sg.Text('Angle of Launch (Degrees)', 
                     size=(35, 1)), sg.InputText(self.defaultAngle)],
            [sg.Text('_' * 80)],
            [sg.ReadButton(self.buttonBack, button_color=('white', 'blue')),
             sg.ReadButton(self.buttonNext)]
        ]

        window = sg.Window('Rocket Simulator Console', default_element_size=(40, 1), grab_anywhere=False)
        window.Layout(layout)
        
        while self.State == State.NON_CONFIGURED or self.State == State.CONFIGURED:
            event, entries = window.ReadNonBlocking()
            
            if event is self.buttonNext:
                print("Next Selected")
                self.assignUIEntries(entries)
                if self.ValidateEntries() == True:
                    self.dataReady = True
                    self.State = State.CONFIGURED
                    self.sendData()
                    #self.State = State.READY
                    self.SubUI()
                else:
                    Popup("Failure", "Please properly enter the Rocket details\n")
                    
            elif event is self.buttonBack:
                print("Reset Selected")
                self.resetValues()
                
    
    def SubUI(self):
        print("Sub") 
        sg.ChangeLookAndFeel(self.colour)
        
        layout = [
            [sg.Text('Welcome to the Rocket Simulator Console (2D)', size=(40, 1), font=("Helvetica", 25))],
            [sg.Text('Please enter the data from the mission to begin')],
            [sg.Text('Pick which pilot to use:'),
             sg.InputCombo((Pilots.FRED, Pilots.RYAN, Pilots.SARAH, Pilots.GRACE), key='pilots', size=(20, 1))],
            [sg.Text('Enter the Planet Terrain Details:', font=("Helvetica", 15))],
            [sg.Text('Acceleration due to Gravity (Max 10)', 
                     size=(35, 1)), sg.InputText(self.defaultGravity)],
            [sg.Text('Define the density of the planets atmosphere:', 
                     size=(35, 1)), sg.InputText(self.defaultDensity)],
            [sg.Text('_' * 80)],
            [sg.Button('Reset Values to Default', button_color=('white', 'blue')),
             sg.ReadButton('Next Page')]
        ]

        window = sg.Window('Rocket Simulator Console', default_element_size=(40, 1), grab_anywhere=False)
        window.Layout(layout)
        
        while self.State != State.RETURN:
            event, entries = window.ReadNonBlocking()
            if event is 'Next Page':
                self.State = State.RETURN
                          
        
    def sendData(self):
        if self.dataReady is True:
            terrain      = terrainDataParameters(self.messageID, self.dataStructure[0], self.dataStructure[1])
            state        = stateDataParameters(self.messageID, self.State)
            #launcher     = launcherMissionParameters(self.messageID, self.defaultPilot, 
            #                                         self.defaultTimeToLaunchMin, self.defaultTimeToLaunchSec)
            rocket       = rocketDataParameters(self.messageID, self.dataStructure[2], self.dataStructure[3], 
                                                self.dataStructure[4], self.dataStructure[5], 
                                                self.dataStructure[6], self.dataStructure[7], 
                                                self.dataStructure[8], self.dataStructure[9], 
                                                self.dataStructure[10])
            terrainData  = terrain.getDataStructure()
            stateData    = state.getDataStructure()
            #launcherData = launcher.getDataStructure()
            rocketData   = rocket.getDataStructure()
            data = stateData + terrainData + rocketData##launcherData + rocketData
            if sendData(data):
                self.messageID = self.messageID + 1
                self.dataReady = False
            
        
    def run(self):
        print ("Starting " + self.name)
        self.MainUI()
        print ("Exiting " + self.name + "\n")
        