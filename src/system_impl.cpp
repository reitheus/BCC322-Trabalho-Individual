#include "../include/system_impl.h"

using namespace std;

// Construtor padrão
System_Impl::System_Impl() : value(0.0), name("") {}

// Construtor com parâmetros
System_Impl::System_Impl(const string& name, double value)
    : value(value), name(name) {}

// Construtor de cópia
System_Impl::System_Impl(const System_Impl& other)
    : value(other.value), name(other.name) {}

// Destrutor
System_Impl::~System_Impl() {}

// Operador de atribuição
System_Impl& System_Impl::operator=(const System_Impl& other) {
    if (this == &other) {
        return *this;
    }

    value = other.value;
    name = other.name;

    return *this;
}

// Retorna o nome do sistema
string System_Impl::getName() const {
    return name;
}

// Altera o nome do sistema
void System_Impl::setName(const string& name) {
    this->name = name;
}

// Retorna o valor armazenado no sistema
double System_Impl::getValue() const {
    return value;
}

// Altera o valor armazenado no sistema
void System_Impl::setValue(double value) {
    this->value = value;
}
