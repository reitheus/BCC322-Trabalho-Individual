CXX = g++

CXXFLAGS = -Wall

SRC_DIR = src
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)%.cpp,$(BIN_DIR)/%.o,$(SRCS))

TARGET = $(BIN_DIR)/prog

all: $(BIN_DIR) $(TARGET)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET) : $(OBJS)
	$(CXX) $^ -o $@

clean:
	rm -rf $(BIN_DIR)/*