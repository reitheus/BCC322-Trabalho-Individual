/**
 * @file flow.cpp
 * @brief Implementação da classe abstrata Flow.
 *
 * Este arquivo contém os métodos responsáveis
 * pela manipulação dos fluxos do simulador.
 */

#include "../include/flow.h"
#include "../include/system.h"

using namespace std;


// =====================
// Construtores
// =====================

/*
 * @brief Construtor padrão da classe Flow.
 *
 * Inicializa:
 * - nome vazio
 * - source nulo
 * - target nulo
 */
Flow::Flow()
    : name(""),
    source(nullptr),
    target(nullptr)
{
}


/*
 * @brief Construtor parametrizado da classe Flow.
 *
 * @param name Nome do fluxo.
 * @param source Sistema de origem.
 * @param target Sistema de destino.
 */
Flow::Flow(const string& name,
    System* source,
    System* target)
    : name(name),
    source(source),
    target(target)
{
}


/*
 * @brief Construtor de cópia da classe Flow.
 *
 * @param other Outro objeto Flow.
 */
Flow::Flow(const Flow& other)
    : name(other.name),
    source(other.source),
    target(other.target)
{
}


// =====================
// Destrutor
// =====================

/*
 * @brief Destrutor da classe Flow.
 */
Flow::~Flow() {}


// =====================
// Operador de atribuição
// =====================

/*
 * @brief Operador de atribuição da classe Flow.
 *
 * Copia os atributos de outro fluxo.
 *
 * @param other Outro objeto Flow.
 * @return Referência para o objeto atual.
 */
Flow& Flow::operator=(const Flow& other) {

    if (this == &other)
        return *this;

    name = other.name;
    source = other.source;
    target = other.target;

    return *this;
}


// =====================
// Getters e Setters
// =====================

/*
 * @brief Retorna o nome do fluxo.
 *
 * @return Nome do fluxo.
 */
string Flow::getName() const {
    return name;
}


/*
 * @brief Define o nome do fluxo.
 *
 * @param name Novo nome do fluxo.
 */
void Flow::setName(const string& name) {
    this->name = name;
}


/*
 * @brief Retorna o sistema de origem.
 *
 * @return Ponteiro para o sistema de origem.
 */
System* Flow::getSource() const {
    return source;
}


/*
 * @brief Define o sistema de origem.
 *
 * @param source Novo sistema de origem.
 */
void Flow::setSource(System* source) {
    this->source = source;
}


/*
 * @brief Retorna o sistema de destino.
 *
 * @return Ponteiro para o sistema de destino.
 */
System* Flow::getTarget() const {
    return target;
}


/*
 * @brief Define o sistema de destino.
 *
 * @param target Novo sistema de destino.
 */
void Flow::setTarget(System* target) {
    this->target = target;
}
