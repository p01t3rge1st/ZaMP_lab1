CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinc
LDFLAGS = -ldl

SRC = src/main.cpp src/Preprocessor.cpp src/LibInterface.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = interpreter
PLUGIN = libexample.so

all: $(TARGET) $(PLUGIN)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

$(PLUGIN): src/example_plugin.cpp
	$(CXX) $(CXXFLAGS) -fPIC -shared $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET) $(PLUGIN)

test: $(TARGET)
	./$(TARGET) test_actions.txt

.PHONY: all clean test
