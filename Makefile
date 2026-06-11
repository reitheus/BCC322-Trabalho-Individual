CXX = g++

SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include

FUNC_TEST_DIR = test/functional
UNIT_TEST_DIR = test/unit

CXXFLAGS = -Wall -Wextra -std=c++17 -I$(INCLUDE_DIR)

# =====================================
# CRIA PASTA BIN SE NÃO EXISTIR
# =====================================

$(shell mkdir -p $(BIN_DIR))

# =====================================
# EXECUTÁVEIS
# =====================================

TARGET = $(BIN_DIR)/prog

FUNC_TARGET = $(BIN_DIR)/progTestFuncional

UNIT_TARGET = $(BIN_DIR)/progTestUnit

# =====================================
# SOURCE FILES
# =====================================

SRC_SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Remove main.cpp do src
LIB_SRCS = $(filter-out $(SRC_DIR)/main.cpp,$(SRC_SRCS))

LIB_OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(LIB_SRCS))

# =====================================
# TESTES FUNCIONAIS
# =====================================

FUNC_TEST_SRCS = $(wildcard $(FUNC_TEST_DIR)/*.cpp)

FUNC_TEST_OBJS = $(patsubst $(FUNC_TEST_DIR)/%.cpp,$(BIN_DIR)/%.func.o,$(FUNC_TEST_SRCS))

# =====================================
# TESTES UNITÁRIOS
# =====================================

UNIT_TEST_SRCS = $(wildcard $(UNIT_TEST_DIR)/*.cpp)

UNIT_MAIN = $(UNIT_TEST_DIR)/main.cpp

UNIT_LIB_SRCS = $(filter-out $(UNIT_MAIN),$(UNIT_TEST_SRCS))

UNIT_TEST_OBJS = $(patsubst $(UNIT_TEST_DIR)/%.cpp,$(BIN_DIR)/%.unit.o,$(UNIT_LIB_SRCS))

UNIT_MAIN_OBJ = $(BIN_DIR)/main.unit.o

# =====================================
# PHONY
# =====================================

.PHONY: all clean functional_tests unit_tests run

# =====================================
# BUILD ALL
# =====================================

all: $(TARGET) $(FUNC_TARGET) $(UNIT_TARGET)

# =====================================
# COMPILAR OBJETOS SRC
# =====================================

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =====================================
# COMPILAR TESTES FUNCIONAIS
# =====================================

$(BIN_DIR)/%.func.o: $(FUNC_TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =====================================
# COMPILAR TESTES UNITÁRIOS
# =====================================

$(BIN_DIR)/%.unit.o: $(UNIT_TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =====================================
# EXECUTÁVEL PRINCIPAL
# =====================================

$(TARGET): $(SRC_DIR)/main.cpp $(LIB_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# =====================================
# EXECUTÁVEL TESTES FUNCIONAIS
# =====================================

$(FUNC_TARGET): $(LIB_OBJS) $(FUNC_TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# =====================================
# EXECUTÁVEL TESTES UNITÁRIOS
# =====================================

$(UNIT_MAIN_OBJ): $(UNIT_MAIN)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(UNIT_TARGET): $(LIB_OBJS) $(UNIT_TEST_OBJS) $(UNIT_MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# =====================================
# EXECUTAR TESTES FUNCIONAIS
# =====================================

functional_tests: $(FUNC_TARGET)
	./$(FUNC_TARGET)

# =====================================
# EXECUTAR TESTES UNITÁRIOS
# =====================================

unit_tests: $(UNIT_TARGET)
	./$(UNIT_TARGET)

# =====================================
# EXECUTAR TODOS OS TESTES
# =====================================

run: functional_tests unit_tests

# =====================================
# LIMPAR ARQUIVOS GERADOS
# =====================================

clean:
	rm -f $(BIN_DIR)/*.o
	rm -f $(BIN_DIR)/*.func.o
	rm -f $(BIN_DIR)/*.unit.o
	rm -f $(TARGET)
	rm -f $(FUNC_TARGET)
	rm -f $(UNIT_TARGET)