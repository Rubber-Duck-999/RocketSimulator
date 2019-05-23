'''
Created on 31 Mar 2019

@author: simon
'''
import time, threading, queue
from CoreGUI import *
exitFlag = 0
     
# Fill the queue
# def add_data(queue):
    # #while not exitFlag and not queue.full():
    # queueLock.acquire()
    # for word in nameList:
        # workQueue.put(word)
        # print("Adding word to put queue")
        # if queue.full():
            # print("Queue is Full")
    # queueLock.release()
        
# def process_data(queue):
    # while not exitFlag:
        # queueLock.acquire()
        # if not workQueue.empty():
            # data = queue.get()
            # queueLock.release()
            # print ("%s processing %s" % (threadName, data))
        # else:
            # queueLock.release()
            # time.sleep(1)
            
queueLock = threading.Lock()
workQueue = queue.Queue(10)
threads = []
myGUI = GUI(workQueue)
myGUI.start()
threads.append(myGUI)

#Wait for queue to empty
while not workQueue.empty():
   pass

#Notify threads it's time to exit
exitFlag = 1

#Wait for all threads to complete
for t in threads:
   t.join()
print ("Exiting Main Thread")    

if __name__ == '__main__':
   pass