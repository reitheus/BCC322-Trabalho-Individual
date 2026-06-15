CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I$(INCLUDE_DIR)

INCLUDE_DIR   = include
SRC_DIR       = src
BIN_DIR       = bin
FUNC_TEST_DIR = test/functional
UNIT_TEST_DIR = test/unit

TARGET      = $(BIN_DIR)/prog
FUNC_TARGET = $(BIN_DIR)/progTestFuncional
UNIT_TARGET = $(BIN_DIR)/progTestUnit

LIB_SRCS = $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp))
LIB_OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(LIB_SRCS))

FUNC_TEST_SRCS = $(wildcard $(FUNC_TEST_DIR)/*.cpp)
FUNC_TEST_OBJS = $(patsubst $(FUNC_TEST_DIR)/%.cpp, $(BIN_DIR)/%.func.o, $(wildcard $(FUNC_TEST_DIR)/*.cpp))

UNIT_TEST_SRCS = $(wildcard $(UNIT_TEST_DIR)/*.cpp)
UNIT_LIB_SRCS  = $(filter-out $(UNIT_TEST_DIR)/main.cpp, $(wildcard $(UNIT_TEST_DIR)/*.cpp))
UNIT_TEST_OBJS = $(patsubst $(UNIT_TEST_DIR)/%.cpp, $(BIN_DIR)/%.unit.o, $(UNIT_LIB_SRCS))
UNIT_MAIN_OBJ  = $(BIN_DIR)/main.unit.o

$(shell mkdir -p $(BIN_DIR))

.PHONY: all run functional_tests unit_tests clean

all: $(TARGET) $(FUNC_TARGET) $(UNIT_TARGET)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/%.func.o: $(FUNC_TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/%.unit.o: $(UNIT_TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(SRC_DIR)/main.cpp $(LIB_OBJS) 
	$(CXX) $(CXXFLAGS) $^ -o $@

$(FUNC_TARGET): $(LIB_OBJS) $(FUNC_TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(UNIT_MAIN_OBJ): $(UNIT_MAIN)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(UNIT_TARGET): $(LIB_OBJS) $(UNIT_TEST_OBJS) $(UNIT_MAIN_OBJ) 
	$(CXX) $(CXXFLAGS) $^ -o $@

functional_tests: $(FUNC_TARGET) 
	./$(FUNC_TARGET)

unit_tests:       $(UNIT_TARGET)
	./$(UNIT_TARGET)

run: functional_tests unit_tests

clean:
	rm -f $(BIN_DIR)/*.o 
	rm -f $(BIN_DIR)/*.func.o 
	rm -f $(BIN_DIR)/*.unit.o
	rm -f $(TARGET) 
	rm -f $(FUNC_TARGET) 
	rm -f $(UNIT_TARGET)