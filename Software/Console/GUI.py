'''
Created on 19 Jan 2019

@author: simon
'''

import sys
import time
from ConsoleDataStructure import Pilots
if sys.version_info[0] >= 3:
    import PySimpleGUI as sg
else:
    import PySimpleGUI27 as sg
from tkinter import *
    

def pySimple():
    sg.ChangeLookAndFeel('Dark')

    for x in range(1, 5):
        sg.OneLineProgressMeter('Loading Console', x+1, 5, 'meter', 'Message')
        time.sleep(1)

    layout = [
        [sg.Text('Welcome to the Rocket Simulator Console (2D)', size=(40, 1), font=("Helvetica", 25))],
        [sg.Text('Please enter the data from the mission to begin')],
        [sg.Text('Pick which pilot to use:'),
         sg.InputCombo((Pilots.FRED, Pilots.RYAN, Pilots.SARAH, Pilots.GRACE), key='pilots', size=(20, 1))],
        
        [sg.Text('Enter the Planet Terrain Details:', font=("Helvetica", 15))],
        [sg.Text('Acceleration due to Gravity (Max 10)', size=(35, 1)), sg.InputText('9.87')],
        [sg.Text('Define the density of the planets atmosphere:', size=(35, 1)), sg.InputText('0.00')],
        
        [sg.Text('Enter the Rocket Details:', font=("Helvetica", 15))],
        [sg.Text('Mass (KG)', size=(35, 1)), sg.InputText('0.00')],
        [sg.Text('Thrust (N)', size=(35, 1)), sg.InputText('0.00')],
        [sg.Text('Drag Coefficient on the X Axis', size=(35, 1)), sg.InputText('0.00')],
        [sg.Text('Drag Coefficient on the Y Axis', size=(35, 1)), sg.InputText('0.00')],
        [sg.Text('Horizontal Cross Sectional Area', size=(35, 1)), sg.InputText('0.00')],
        [sg.Text('Vertical Cross Sectional Area', size=(35, 1)), sg.InputText('0.00')],
        [sg.Text('Burn Time', size=(35, 1)), sg.InputText('0.00')],
        [sg.Text('Flow Rate of the Fuel', size=(35, 1)), sg.InputText('0.00')],
        [sg.Text('Angle of Launch (Degrees)', size=(35, 1)), sg.InputText('0.00')],
        
        [sg.Text('_' * 80)],
        [sg.Button('Reset Values to Default', button_color=('white', 'blue')),
         sg.ReadButton('Next Page')]
    ]

    window = sg.Window('Rocket Simulator Console', default_element_size=(40, 1), grab_anywhere=False)
    window.Layout(layout)

    while True:
        event, values = window.ReadNonBlocking()
        sg.Popup(event, values)
        
        if event is 'SaveSettings':
            filename = sg.PopupGetFile('Save Settings', save_as=True, no_window=True)
            window.SaveToDisk(filename)
            # save(values)
        elif event is 'LoadSettings':
            filename = sg.PopupGetFile('Load Settings', no_window=True)
            window.LoadFromDisk(filename)
            # load(form)
        elif event in ['Next Page', None]:
            break

    # window.CloseNonBlocking()

#tkinter()
print("hello")
pySimple()
