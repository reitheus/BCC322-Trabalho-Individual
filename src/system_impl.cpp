/**
 * @file system_impl.cpp
 * @brief Implementação da classe System_Impl.
 *
 * Este arquivo contém a implementação dos métodos responsáveis
 * pela manipulação dos sistemas do simulador, incluindo
 * construtores, destrutor, operador de atribuição e
 * getters/setters de nome e valor.
 */

#include "../include/system_impl.h"

using namespace std;

/**
 * @brief Construtor padrão da classe System_Impl.
 *
 * Inicializa o sistema com valor igual a 0.0 e nome vazio.
 */
System_Impl::System_Impl() : value(0.0), name("") {}

/**
 * @brief Construtor parametrizado da classe System_Impl.
 *
 * @param name Nome do sistema.
 * @param value Valor inicial do sistema.
 */
System_Impl::System_Impl(const string& name, double value)
    : value(value), name(name) {
}

/**
 * @brief Construtor de cópia da classe System_Impl.
 *
 * @param other Objeto System_Impl a ser copiado.
 */
System_Impl::System_Impl(const System_Impl& other)
    : value(other.value), name(other.name) {
}

/**
 * @brief Destrutor da classe System_Impl.
 */
System_Impl::~System_Impl() {}

/**
 * @brief Operador de atribuição da classe System_Impl.
 *
 * Copia nome e valor de outro objeto System_Impl.
 *
 * @param other Objeto System_Impl a ser atribuído.
 * @return Referência para o objeto atual.
 */
System_Impl& System_Impl::operator=(const System_Impl& other) {
    if (this == &other)
        return *this;

    value = other.value;
    name = other.name;

    return *this;
}

/**
 * @brief Retorna o nome do sistema.
 *
 * @return Nome do sistema.
 */
string System_Impl::getName() const {
    return name;
}

/**
 * @brief Define o nome do sistema.
 *
 * @param name Novo nome do sistema.
 */
void System_Impl::setName(const string& name) {
    this->name = name;
}

/**
 * @brief Retorna o valor atual armazenado no sistema.
 *
 * @return Valor do sistema.
 */
double System_Impl::getValue() const {
    return value;
}

/**
 * @brief Define o valor armazenado no sistema.
 *
 * @param value Novo valor do sistema.
 */
void System_Impl::setValue(double value) {
    this->value = value;
}