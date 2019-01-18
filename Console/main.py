# ! usr/bin/pyhton3

import socket
import sys
#from TerrainMissionParameters import TerrainMissionParameters
from SocketSender import SocketSender
from TerrainMissionParameters import TerrainMissionParametersSocketSender

	
mySocket = TerrainMissionParametersSocketSender("", 61377, 10)
mySocket.set_sendDataID('101')
mySocket.run()
mySocket.close()
