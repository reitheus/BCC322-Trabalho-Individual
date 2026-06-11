#include "../include/flow_impl.h"
#include "../include/system_impl.h"
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


// Construtor padrão
Flow_Impl::Flow_Impl()

/**
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


/**
 * @brief Construtor parametrizado da classe Flow.
 *
 * @param name Nome do fluxo.
 * @param source Sistema de origem.
 * @param target Sistema de destino.
 */
// Construtor com parâmetros
Flow_Impl::Flow_Impl(const string& name,
           System* source,
           System* target)
    : name(name),
    source(source),
    target(target)
{
}


/**
 * @brief Construtor de cópia da classe Flow.
 *
 * @param other Outro objeto Flow.
 */
 // Construtor de cópia
Flow_Impl::Flow_Impl(const Flow_Impl& other)
    : name(other.name),
    source(other.source),
    target(other.target)
{
}


// =====================
// Destrutor
/**
 * @brief Destrutor da classe Flow.
 */
Flow_Impl::~Flow_Impl() {}

// Operador de atribuição

/**
 * @brief Operador de atribuição da classe Flow.
 *
 * Copia os atributos de outro fluxo.
 *
 * @param other Outro objeto Flow.
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



// Getters e Setters

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


// Retorna source
System* Flow_Impl::getSource() const {
    return source;
}


/**
 * @brief Retorna o sistema de origem.
 *
 * @return Ponteiro para o sistema de origem.
 */
void Flow_Impl::setSource(System* source) {
    this->source = source;
}


/**
 * @brief Retorna o sistema de destino.
 *
 * @return Ponteiro para o sistema de destino.
 */
System* Flow_Impl::getTarget() const {
    return target;
}


/**
 * @brief Define o sistema de destino.
 *
 * @param target Novo sistema de destino.
 */
void Flow_Impl::setTarget(System* target) {
    this->target = target;
}
