CXX = g++

CXXFLAGS = -Wall

SRC_DIR = src
BIN_DIR = bin
TEST_DIR = test/functional
TARGET = $(BIN_DIR)/prog
TEST_TARGET = $(BIN_DIR)/testeRegressivo.exe

# Source files
SRC_SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Exclude main.cpp from library objects
LIB_SRCS = $(filter-out $(SRC_DIR)/main.cpp,$(SRC_SRCS))
LIB_OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(LIB_SRCS))

TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp,$(BIN_DIR)/%.test.o,$(TEST_SRCS))

.PHONY: all clean

all: $(TARGET) $(TEST_TARGET)

# Compilar objetos da biblioteca
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilar objetos de teste
$(BIN_DIR)/%.test.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Gerar executável principal
$(TARGET): $(SRC_DIR)/main.cpp $(LIB_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Gerar executável de teste
$(TEST_TARGET): $(LIB_OBJS) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(BIN_DIR)/*.o $(BIN_DIR)/*.test.o $(TARGET) $(TEST_TARGET)
