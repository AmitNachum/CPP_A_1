CXX = g++
CXXFLAGS = -std=c++11 -g $(DOCTEST)
DOCTEST = -I/usr/include/doctest/
SROUCES = Priority_Queue.cpp Test_PQ.cpp
OBJECTS = $(SROUCES:.cpp=.o)
TARGET = testingPQ
VAL = valgrind


all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


run: $(TARGET)
	$(VAL) ./$(TARGET)


clean:
	rm $(OBJECTS) $(TARGET)


.PHONY: all clean run

