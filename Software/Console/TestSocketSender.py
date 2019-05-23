import unittest
from SocketSender import *
from ConsoleDataStructure import *

Host = "127.0.0.1"
Port = 6111

class TestSocketSenderMethods(unittest.TestCase):

    def test_setDataPackageState(self):
        Socket = SocketSender(Host, Port)
        state = stateDataParameters(100, State.NON_CONFIGURED)
        valueToCheck = Socket.setDataPackage(state.getDataStructure())
        self.assertTrue(valueToCheck)
        
    def test_setDataPackageAll(self):
        Socket = SocketSender(Host, Port)
        state = stateDataParameters(100, State.CONFIGURED)
        state = rocketDataParameters(100, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
        state = launcherMissionParameters(100, Pilots.FRED, 0.0, 0.0)
        state = terrainDataParameters(100, 0.0, 0.0)
        valueToCheck = Socket.setDataPackage(state.getDataStructure())
        self.assertTrue(valueToCheck)
        
    def test_setDataPackageState_Fail(self):
        Socket = SocketSender(Host, Port)
        valueToCheck = Socket.setDataPackage([0])
        self.assertFalse(valueToCheck)
        
    def test_connect(self):
        Socket = SocketSender(Host, Port)
        state = stateDataParameters(100, State.NON_CONFIGURED)
        valueSet = Socket.setDataPackage(state.getDataStructure())
        if valueSet:
            valueConnect = Socket.connect()
            self.assertFalse(valueConnect)
        
    def test_dummy(self):
        self.assertEqual(30, 30)
        
        
if __name__ == '__main__':
    unittest.main()