CXX = g++

CXXFLAGS = -Wall -std=c++11 -I$(INCLUDE_DIR)

SRC_DIR = src
BIN_DIR = bin
TEST_DIR = test/functional
INCLUDE_DIR = include

$(shell mkdir -p $(BIN_DIR))

TARGET = $(BIN_DIR)/prog
TEST_TARGET = $(BIN_DIR)/testeRegressivo

# Source files
SRC_SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Exclude main.cpp from library objects
LIB_SRCS = $(filter-out $(SRC_DIR)/main.cpp,$(SRC_SRCS))

LIB_OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(LIB_SRCS))

TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)

TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp,$(BIN_DIR)/%.test.o,$(TEST_SRCS))

.PHONY: all clean

all: $(TARGET) $(TEST_TARGET)

# Compile library objects
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test objects
$(BIN_DIR)/%.test.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Main executable
$(TARGET): $(SRC_DIR)/main.cpp $(LIB_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Functional tests executable
$(TEST_TARGET): $(LIB_OBJS) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(BIN_DIR)/*.o
	rm -f $(BIN_DIR)/*.test.o
	rm -f $(TARGET)
	rm -f $(TEST_TARGET)
