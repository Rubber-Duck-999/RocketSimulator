import unittest
from SocketSender import *
from ConsoleDataStructure import *

Host = "127.0.0.1"
Port = 6111

class TestSocketSenderMethods(unittest.TestCase):
        
    def test_setDataPackageAll(self):
        Socket = SocketSender(Host, Port)
        terrain = terrainDataParameters(100, 0.0, 0.0)
        valueToCheck = Socket.setDataPackage(terrain.getDataStructure())
        self.assertTrue(valueToCheck)
        
    def test_setDataPackageState_Fail(self):
        Socket = SocketSender(Host, Port)
        valueToCheck = Socket.setDataPackage([0])
        self.assertFalse(valueToCheck)
        
    def test_dummy(self):
        self.assertEqual(30, 30)
        
        
if __name__ == '__main__':
    unittest.main()