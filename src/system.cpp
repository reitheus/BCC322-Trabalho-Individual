#include "../include/system.h"

using namespace std;

// Construtor padrão
System::System() : value(0.0), name("") {}

// Construtor com parâmetros
System::System(const string& name, double value)
    : value(value), name(name) {}

// Construtor de cópia
System::System(const System& other)
    : value(other.value), name(other.name) {}

// Destrutor
System::~System() {}

// Operador de atribuição
System& System::operator=(const System& other) {
    if (this == &other) {
        return *this;
    }

    value = other.value;
    name = other.name;

    return *this;
}

// Retorna o nome do sistema
string System::getName() const {
    return name;
}

// Altera o nome do sistema
void System::setName(const string& name) {
    this->name = name;
}

// Retorna o valor armazenado no sistema
double System::getValue() const {
    return value;
}

// Altera o valor armazenado no sistema
void System::setValue(double value) {
    this->value = value;
}
