'''
Created on 19 Jan 2019

@author: simon
'''

import sys, time
from ConsoleDataStructure import *
from SocketSender import *
from PySimpleGUI.PySimpleGUI import Popup
if sys.version_info[0] >= 3:
    import PySimpleGUI as sg

Port = 6111
Host = "127.0.0.1"

class GUI():
    def __init__(self):
        self.buttonBack = 'Reset Values to Default'
        self.buttonNext = 'Next Page'
        self.Socket = SocketSender(Host, Port)
        if not self.Socket.connect():
            print("Socket could not be connected")
            self.Socket.close()
        self.resetValues()
        
    def resetValues(self):    
        self.defaultPilot     = Pilots.BOB
        self.defaultGravity   = 9.87
        self.defaultDensity   = 1.22
        self.defaultMass      = 80.00
        self.defaultThrust    = 10.00
        self.defaultDragAxisX = 0.30
        self.defaultDragAxisY = 0.30
        self.defaultHoriCross = 1.00
        self.defaultVertCross = 1.00
        self.defaultBurnTime  = 50.00
        self.defaultFlowRate  = 20.00
        self.defaultAngle     = 90.00
        self.dataStructure    = [ self.defaultGravity, self.defaultDensity, self.defaultMass,      
                                  self.defaultThrust, self.defaultDragAxisX, self.defaultDragAxisY, 
                                  self.defaultHoriCross, self.defaultVertCross, self.defaultBurnTime,  
                                  self.defaultFlowRate, self.defaultAngle ]
        self.colour    = 'Dark'
        self.messageID = 101 
        self.dataReady = False     
        self.defaultTimeToLaunchSec = 50.00
                      
    def Validate(self, value, MIN, MAX):
        if value < MIN or value > MAX:
            return False
        else:
            return True
        
    def ValidateEntries(self):
        MIN = 0.00
        output = True
        for name in self.dataStructure:
            if not self.Validate(name, MIN, 100.0):
                output = False
        return output
    
    def assignUIEntries(self, entries):
        i = 0
        print("Assigning UI Values")
        for name in self.dataStructure:
            name = float(entries[i])
            self.dataStructure[i] = name
            i = i + 1   
        print(self.dataStructure)
          
    def MainUI(self):
        print("Entering Main Screen")
        sg.ChangeLookAndFeel(self.colour)
        layout = [
            [sg.Text('Welcome to the Rocket Simulator Console (2D)', size=(40, 1), font=("Helvetica", 25))],
            [sg.Text('Please enter the data from the mission to begin')],
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
             sg.ReadButton(self.buttonNext)]]
        window = sg.Window('Rocket Simulator Console', default_element_size=(40, 1), grab_anywhere=False)
        window.Layout(layout)
        while self.x:
            event, entries = window.ReadNonBlocking()
            if event is self.buttonNext:
                print("Next Selected")
                self.assignUIEntries(entries)
                if self.ValidateEntries() == True:
                    self.sendMainData()
                    while self.receiveData() == 2:
                        self.SubUI()
                else:
                    Popup("Failure", "Please properly enter the Rocket details\n")
            elif event is self.buttonBack:
                print("Reset Selected")
                self.resetValues()       
    
    def SubUI(self):
        print("Sub") 
        sg.ChangeLookAndFeel(self.colour)
        Button_Next = "Move to Launch"
        Button_Restart = 'Restart'
        layout = [
            [sg.Text('Welcome to the Rocket Simulator Console (2D)', size=(40, 1), font=("Helvetica", 25))],
            [sg.Text('Please enter the Launcher Data required for Launch')],
            [sg.Text('Pick which pilot to use:'),
             sg.InputCombo((Pilots.BOB, Pilots.FRED, Pilots.RYAN, Pilots.SARAH, Pilots.GRACE), key='Pilots', size=(20, 1))],
            [sg.Text('Enter the Launch Time (Seconds):', 
                     size=(35, 1)), sg.InputText(self.defaultTimeToLaunchSec)],
            [sg.Text('_' * 80)],
            [sg.ReadButton(Button_Restart, button_color=('white', 'red')),
             sg.ReadButton(Button_Next)]]
        window = sg.Window('Rocket Simulator Console', default_element_size=(40, 1), grab_anywhere=False)
        window.Layout(layout)
        while self.x:
            event, entries = window.ReadNonBlocking()
            if event is Button_Next:
                self.defaultPilot = entries.get(Pilots)
                self.sendLauncherData()
                print("Running Sim")
                recv = 3
                while recv == 3:
                    self.Socket.receiveMessage()
                    recv = self.receiveData()
                self.x = False
            elif event is Button_Restart:
                print("Reset Selected")
                self.resetValues()
            
    def sendMainData(self):
        terrain      = terrainDataParameters(self.messageID, self.dataStructure[0], self.dataStructure[1])
        rocket       = rocketDataParameters(self.messageID, self.dataStructure[2], self.dataStructure[3], 
                                            self.dataStructure[4], self.dataStructure[5], 
                                            self.dataStructure[6], self.dataStructure[7], 
                                            self.dataStructure[8], self.dataStructure[9], 
                                            self.dataStructure[10])
        terrainData  = terrain.getDataStructure()
        rocketData   = rocket.getDataStructure()
        data = terrainData + rocketData
        print("Sending main data to Controller")
        if self.Socket.setDataPackage(data):
            self.Socket.sendMessages()
            self.messageID = self.messageID + 1

    def sendLauncherData(self):
        launcher     = launcherMissionParameters(self.messageID, self.defaultPilot, self.defaultTimeToLaunchSec)
        launcherData   = launcher.getDataStructure()
        print("Sending launcher data to Controller")
        if self.Socket.setDataPackage(launcherData):
            self.Socket.sendMessages()
            self.messageID = self.messageID + 1
     
    def setMessageId(self, id):
        if self.messageID == id:
            print("We have a mismatch of id's on sender and receiver, setting to their id")
        elif self.messageID > id:
            print("We have an expected id")
            self.messageID += 1
            
    def receiveData(self):
        print("Receive messages from the controller accessor")
        print("We received: " + self.Socket.currentMessage)
        if "State:0" in self.Socket.currentMessage:
            print("Controller has not validated our data")
            return 0
        elif "State:1" in self.Socket.currentMessage:
            print("Controller has not moved to Ready, we should never recieve a configured reply")
            return 1
        elif "State:2" in self.Socket.currentMessage:
            print("Launch can be, we can move to launch now")
            return 2
        elif "State:3" in self.Socket.currentMessage:
            print("Launch has begun, we can not move out of launch until simulation is complete")
            return 3
        elif "State:4" in self.Socket.currentMessage:
            print("We have been asked to return to non configured by Controller")
            return 4
        elif "State:5" in self.Socket.currentMessage:
            print("We have been told to Shutdown and our shutdown was accepted")
            return 5
     
    def run(self):
        print ("Starting GUI")
        self.x = True
        self.MainUI()
        print("Exiting GUI\n")
        self.Socket.close()
        