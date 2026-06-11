<<<<<<< HEAD:src/system.cpp
/**
 * @file system.cpp
 * @brief Implementação da classe System.
 *
 * Este arquivo contém a implementação dos métodos
 * responsáveis pela manipulação dos sistemas
 * do simulador.
 */

#include "../include/system.h"

using namespace std;

// =====================
// Construtores
// =====================

/*
 * @brief Construtor padrão da classe System.
 *
 * Inicializa o sistema com:
 * - valor igual a 0.0
 * - nome vazio
 */
System::System() : value(0.0), name("") {}

/*
 * @brief Construtor parametrizado da classe System.
 *
 * @param name Nome do sistema.
 * @param value Valor inicial do sistema.
 */
System::System(const string& name, double value)
    : value(value), name(name) {
}

/*
 * @brief Construtor de cópia da classe System.
 *
 * @param other Outro objeto System.
 */
System::System(const System& other)
    : value(other.value), name(other.name) {
}

// =====================
// Destrutor
// =====================

/*
 * @brief Destrutor da classe System.
 */
System::~System() {}

// =====================
// Operador de atribuição
// =====================

/*
 * @brief Operador de atribuição da classe System.
 *
 * Copia os atributos de outro objeto System.
 *
 * @param other Outro objeto System.
 * @return Referência para o objeto atual.
 */
System& System::operator=(const System& other) {
    if (this == &other) {
        return *this;
    }

    value = other.value;
    name = other.name;

    return *this;
}

// =====================
// Getters e Setters
// =====================

/*
 * @brief Retorna o nome do sistema.
 *
 * @return Nome do sistema.
 */
string System::getName() const {
    return name;
}

/*
 * @brief Define o nome do sistema.
 *
 * @param name Novo nome do sistema.
 */
void System::setName(const string& name) {
    this->name = name;
}

/*
 * @brief Retorna o valor atual do sistema.
 *
 * @return Valor armazenado no sistema.
 */
double System::getValue() const {
    return value;
}

/*
 * @brief Define o valor do sistema.
 *
 * @param value Novo valor do sistema.
 */
void System::setValue(double value) {
    this->value = value;
}
=======
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
>>>>>>> develop:src/system_impl.cpp
