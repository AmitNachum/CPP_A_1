CXX = g++
CXXFLAGS = -std=c++11 -g -I./Queue -I./Stack -I./Union_Find -I./Priority_Queue 

TARGET = testingOutputG

SOURCES = graph/Graph.cpp graph/Algorithms.cpp graph/testingOutputG.cpp \
          Queue/Queue.cpp Priority_Queue/Priority_Queue.cpp \
          Union_Find/Union_Find.cpp Stack/stk.cpp 

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) 
