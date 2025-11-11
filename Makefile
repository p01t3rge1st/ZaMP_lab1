CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinc
LDFLAGS = -ldl

SRC = src/main.cpp src/Preprocessor.cpp src/LibInterface.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = interpreter

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

test: $(TARGET)
	./$(TARGET) test_actions.txt

.PHONY: all clean test
