/*
  @file flows.cpp
  @brief Implementação dos fluxos do simulador.
 
  Este arquivo contém as implementações dos fluxos:
  - exponencial
  - logístico
  - complexo
 */

#include "flow.h"
#include "system.h"

 // FlowExponencial
 
 /*
   @brief Construtor padrão da classe FlowExponencial.
  */
FlowExponencial::FlowExponencial() : Flow() {}

/*
  @brief Construtor parametrizado da classe FlowExponencial.
 
  @param name Nome do fluxo.
  @param source Sistema de origem.
  @param target Sistema de destino.
 */
FlowExponencial::FlowExponencial(
    const string& name,
    System* source,
    System* target
) : Flow(name, source, target) {
}

/*
  @brief Construtor de cópia da classe FlowExponencial.
 
  @param other Outro objeto FlowExponencial.
 */
FlowExponencial::FlowExponencial(
    const FlowExponencial& other
) : Flow(other) {
}

/*
  @brief Destrutor da classe FlowExponencial.
 */
FlowExponencial::~FlowExponencial() {}

/*
  @brief Operador de atribuição da classe FlowExponencial.
 
  @param other Outro objeto FlowExponencial.
  @return Referência para o objeto atual.
 */
FlowExponencial& FlowExponencial::operator=(
    const FlowExponencial& other
    ) {
    if (this == &other) {
        return *this;
    }

    Flow::operator=(other);
    return *this;
}

/*
  @brief Executa o cálculo do fluxo exponencial.
 
  O valor transferido corresponde a 1% do valor do sistema de origem.
 
  @return Valor calculado do fluxo.
 */
double FlowExponencial::execute() {
    return 0.01 * getSource()->getValue();
}


// FlowLogistico
/*
  @brief Construtor padrão da classe FlowLogistico.
 */
FlowLogistico::FlowLogistico() : Flow() {}

/*
  @brief Construtor parametrizado da classe FlowLogistico.
 
  @param name Nome do fluxo.
  @param source Sistema de origem.
  @param target Sistema de destino.
 */
FlowLogistico::FlowLogistico(
    const string& name,
    System* source,
    System* target
) : Flow(name, source, target) {
}

/*
  @brief Construtor de cópia da classe FlowLogistico.
 
  @param other Outro objeto FlowLogistico.
 */
FowLogistico::FlowLogistico(
    const FlowLogistico& other
) : Flow(other) {
}

/*
  @brief Destrutor da classe FlowLogistico.
 */
FlowLogistico::~FlowLogistico() {}

/*
  @brief Operador de atribuição da classe FlowLogistico.
 
  @param other Outro objeto FlowLogistico.
  @return Referência para o objeto atual.
 */
FlowLogistico& FlowLogistico::operator=(
    const FlowLogistico& other
    ) {
    if (this == &other) {
        return *this;
    }

    Flow::operator=(other);
    return *this;
}

/*
  @brief Executa o cálculo do fluxo logístico.
 
  Calcula o crescimento logístico considerando a capacidade limite do sistema.
 
  @return Valor calculado do fluxo.
 */
double FlowLogistico::execute() {
    double p = getTarget()->getValue();

    return 0.01 * p * (1 - p / 70.0);
}


// FlowComplexo

/*
  @brief Construtor padrão da classe FlowComplexo.
 */
FlowComplexo::FlowComplexo() : Flow() {}

/*
  @brief Construtor parametrizado da classe FlowComplexo.
 
  @param name Nome do fluxo.
  @param source Sistema de origem.
  @param target Sistema de destino.
 */
FlowComplexo::FlowComplexo(
    const string& name,
    System* source,
    System* target
) : Flow(name, source, target) {
}

/*
  @brief Construtor de cópia da classe FlowComplexo.
 
  @param other Outro objeto FlowComplexo.
 */
FlowComplexo::FlowComplexo(
    const FlowComplexo& other
) : Flow(other) {
}

/*
  @brief Destrutor da classe FlowComplexo.
 */
FlowComplexo::~FlowComplexo() {}

/*
  @brief Operador de atribuição da classe FlowComplexo.
 
  @param other Outro objeto FlowComplexo.
  @return Referência para o objeto atual.
 */
FlowComplexo& FlowComplexo::operator=(
    const FlowComplexo& other
    ) {
    if (this == &other) {
        return *this;
    }

    Flow::operator=(other);
    return *this;
}

/*
  @brief Executa o cálculo do fluxo complexo.
 
  Calcula a transferência entre sistemas utilizando o modelo complexo.
 
  @return Valor calculado do fluxo.
 */
double FlowComplexo::execute() {
    return 0.01 * getSource()->getValue();
}