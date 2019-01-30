CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		Rocket.o Thrust.o World.o AlgorithmTry.o

LIBS =

TARGET =	AlgorithmTry.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
