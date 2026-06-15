/**
 * @file flow_impl.cpp
 * @brief Implementação da classe Flow_Impl.
 *
 * Este arquivo contém os métodos responsáveis pela manipulação
 * dos fluxos do simulador, incluindo construtores, destrutor,
 * operador de atribuição e getters/setters.
 */

#include "../include/flow_impl.h"
#include "../include/system.h"

using namespace std;

/**
 * @brief Construtor padrão da classe Flow_Impl.
 *
 * Inicializa o fluxo com nome vazio, source nulo e target nulo.
 */
Flow_Impl::Flow_Impl()
    : name(""),
      source(nullptr),
      target(nullptr)
{}

/**
 * @brief Construtor parametrizado da classe Flow_Impl.
 *
 * @param name Nome do fluxo.
 * @param source Ponteiro para o sistema de origem.
 * @param target Ponteiro para o sistema de destino.
 */
Flow_Impl::Flow_Impl(const string& name,
    System* source,
    System* target)
    : name(name),
      source(source),
      target(target)
{}

/**
 * @brief Construtor de cópia da classe Flow_Impl.
 *
 * @param other Objeto Flow_Impl a ser copiado.
 */
Flow_Impl::Flow_Impl(const Flow_Impl& other)
    : name(other.name),
      source(other.source),
      target(other.target)
{}

/**
 * @brief Destrutor da classe Flow_Impl.
 */
Flow_Impl::~Flow_Impl() {}

/**
 * @brief Operador de atribuição da classe Flow_Impl.
 *
 * Copia nome, source e target de outro objeto Flow_Impl.
 *
 * @param other Objeto Flow_Impl a ser atribuído.
 * @return Referência para o objeto atual.
 */
Flow_Impl& Flow_Impl::operator=(const Flow_Impl& other) {
    if (this == &other)
        return *this;

    name = other.name;
    source = other.source;
    target = other.target;

    return *this;
}

/**
 * @brief Retorna o nome do fluxo.
 *
 * @return Nome do fluxo.
 */
string Flow_Impl::getName() const {
    return name;
}

/**
 * @brief Define o nome do fluxo.
 *
 * @param name Novo nome do fluxo.
 */
void Flow_Impl::setName(const string& name) {
    this->name = name;
}

/**
 * @brief Retorna o ponteiro para o sistema de origem.
 *
 * @return Ponteiro para o sistema de origem.
 */
System* Flow_Impl::getSource() const {
    return source;
}

/**
 * @brief Define o sistema de origem do fluxo.
 *
 * @param source Ponteiro para o novo sistema de origem.
 */
void Flow_Impl::setSource(System* source) {
    this->source = source;
}

/**
 * @brief Retorna o ponteiro para o sistema de destino.
 *
 * @return Ponteiro para o sistema de destino.
 */
System* Flow_Impl::getTarget() const {
    return target;
}

/**
 * @brief Define o sistema de destino do fluxo.
 *
 * @param target Ponteiro para o novo sistema de destino.
 */
void Flow_Impl::setTarget(System* target) {
    this->target = target;
}