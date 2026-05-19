CXX = g++

CXXFLAGS = -Wall -std=c++11 -I$(INCLUDE_DIR)

SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include

FUNC_TEST_DIR = test/functional
UNIT_TEST_DIR = test/unit

$(shell mkdir -p $(BIN_DIR))

# =========================
# EXECUTÁVEIS
# =========================

TARGET = $(BIN_DIR)/prog

FUNC_TARGET = $(BIN_DIR)/progTestFuncional

UNIT_TARGET = $(BIN_DIR)/progTestUnit

# =========================
# SOURCE FILES
# =========================

SRC_SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Remove main.cpp da biblioteca
LIB_SRCS = $(filter-out $(SRC_DIR)/main.cpp,$(SRC_SRCS))

LIB_OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(LIB_SRCS))

# =========================
# FUNCTIONAL TESTS
# =========================

FUNC_TEST_SRCS = $(wildcard $(FUNC_TEST_DIR)/*.cpp)

FUNC_TEST_OBJS = $(patsubst $(FUNC_TEST_DIR)/%.cpp,$(BIN_DIR)/%.func.o,$(FUNC_TEST_SRCS))

# =========================
# UNIT TESTS
# =========================

UNIT_TEST_SRCS = $(wildcard $(UNIT_TEST_DIR)/*.cpp)

UNIT_TEST_OBJS = $(patsubst $(UNIT_TEST_DIR)/%.cpp,$(BIN_DIR)/%.unit.o,$(UNIT_TEST_SRCS))

# =========================
# PHONY
# =========================

.PHONY: all clean functional_tests unit_tests

# =========================
# BUILD ALL
# =========================

all: $(TARGET) $(FUNC_TARGET) $(UNIT_TARGET)

# =========================
# COMPILAR OBJETOS SRC
# =========================

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =========================
# COMPILAR OBJETOS FUNCIONAIS
# =========================

$(BIN_DIR)/%.func.o: $(FUNC_TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =========================
# COMPILAR OBJETOS UNITÁRIOS
# =========================

$(BIN_DIR)/%.unit.o: $(UNIT_TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =========================
# EXECUTÁVEL PRINCIPAL
# =========================

$(TARGET): $(SRC_DIR)/main.cpp $(LIB_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# =========================
# TESTES FUNCIONAIS
# =========================

$(FUNC_TARGET): $(LIB_OBJS) $(FUNC_TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# =========================
# TESTES UNITÁRIOS
# =========================

$(UNIT_TARGET): $(LIB_OBJS) $(UNIT_TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# =========================
# EXECUTAR TESTES
# =========================

functional_tests: $(FUNC_TARGET)
	./$(FUNC_TARGET)

unit_tests: $(UNIT_TARGET)
	./$(UNIT_TARGET)

# =========================
# CLEAN
# =========================

clean:
	rm -f $(BIN_DIR)/*.o
	rm -f $(BIN_DIR)/*.func.o
	rm -f $(BIN_DIR)/*.unit.o
	rm -f $(TARGET)
	rm -f $(FUNC_TARGET)
	rm -f $(UNIT_TARGET)
