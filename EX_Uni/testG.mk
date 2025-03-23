CXX = g++
CXXFLAGS = -std=c++11 -g -I./Priority_Queue -I./Queue -I./Stack -I./Union_Find -I./Algorithms


SOURCES = graph/Graph.cpp graph/Algorithms.cpp graph/testG.cpp \
          Queue/Queue.cpp Priority_Queue/Priority_Queue.cpp \
          Union_Find/Union_Find.cpp Stack/stk.cpp 

OBJECTS = $(SOURCES:.cpp=.o)
TARGET = testG

all: $(TARGET)


$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
