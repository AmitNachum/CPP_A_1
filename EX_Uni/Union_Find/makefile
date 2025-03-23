CXX = g++
CXXFLAGS = -std=c++11 -g $(DOCTEST)
DOCTEST = -I/usr/include/doctest/
SROUCES = Union_Find.cpp Union_Find_Test.cpp
OBJECTS = $(SROUCES:.cpp=.o)
TARGET = testingUF
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

