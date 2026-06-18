#ifndef FLOWS_H
#define FLOWS_H

#include "../src/flow_impl.h"

/**
 * @file flows.h
 * @brief Declaração das classes de fluxo concretas: exponencial, logístico e complexo.
 */

 /**
  * @brief Fluxo baseado em crescimento exponencial.
  *
  * Implementa uma equação de fluxo exponencial entre dois sistemas,
  * onde a taxa de transferência é proporcional ao valor atual do
  * sistema de origem. Tipicamente usada para modelar crescimento
  * ou decaimento exponencial em populações e recursos.
  */
class FlowExponencial : public Flow_Impl {
public:

    /**
     * @brief Construtor padrão da classe FlowExponencial.
     */
    FlowExponencial();

    /**
     * @brief Construtor parametrizado da classe FlowExponencial.
     *
     * @param name Nome do fluxo.
     * @param source Ponteiro para o sistema de origem.
     * @param target Ponteiro para o sistema de destino.
     */
    FlowExponencial(
        const string& name,
        System* source,
        System* target
    );

    /**
     * @brief Construtor de cópia da classe FlowExponencial.
     *
     * @param other Objeto FlowExponencial a ser copiado.
     */
    FlowExponencial(
        const FlowExponencial& other
    );

    /**
     * @brief Destrutor virtual da classe FlowExponencial.
     */
    virtual ~FlowExponencial();

    /**
     * @brief Operador de atribuição da classe FlowExponencial.
     *
     * @param other Objeto FlowExponencial a ser atribuído.
     * @return Referência para o objeto atual.
     */
    FlowExponencial& operator=(
        const FlowExponencial& other
    );

    /**
     * @brief Executa o cálculo do fluxo exponencial.
     *
     * Calcula a quantidade transferida do sistema de origem para o
     * sistema de destino com base em uma equação de crescimento
     * exponencial aplicada ao valor atual do sistema de origem.
     *
     * @return Valor calculado pelo fluxo exponencial.
     */
    double execute() override;
};

/**
 * @brief Fluxo baseado em crescimento logístico.
 *
 * Implementa uma equação de fluxo logístico entre dois sistemas,
 * onde a taxa de transferência desacelera conforme o sistema de
 * origem se aproxima de uma capacidade limite. Usada para modelar
 * crescimento populacional com capacidade de suporte.
 */
class FlowLogistico : public Flow_Impl {
public:

    /**
     * @brief Construtor padrão da classe FlowLogistico.
     */
    FlowLogistico();

    /**
     * @brief Construtor parametrizado da classe FlowLogistico.
     *
     * @param name Nome do fluxo.
     * @param source Ponteiro para o sistema de origem.
     * @param target Ponteiro para o sistema de destino.
     */
    FlowLogistico(
        const string& name,
        System* source,
        System* target
    );

    /**
     * @brief Construtor de cópia da classe FlowLogistico.
     *
     * @param other Objeto FlowLogistico a ser copiado.
     */
    FlowLogistico(
        const FlowLogistico& other
    );

    /**
     * @brief Destrutor virtual da classe FlowLogistico.
     */
    virtual ~FlowLogistico();

    /**
     * @brief Operador de atribuição da classe FlowLogistico.
     *
     * @param other Objeto FlowLogistico a ser atribuído.
     * @return Referência para o objeto atual.
     */
    FlowLogistico& operator=(
        const FlowLogistico& other
    );

    /**
     * @brief Executa o cálculo do fluxo logístico.
     *
     * Calcula a quantidade transferida do sistema de origem para o
     * sistema de destino com base em uma equação de crescimento
     * logístico, levando em conta os valores atuais de ambos os sistemas.
     *
     * @return Valor calculado pelo fluxo logístico.
     */
    double execute() override;
};

/**
 * @brief Fluxo com equação de múltiplas interações entre sistemas.
 *
 * Implementa um fluxo mais elaborado que combina interações entre
 * o sistema de origem e o sistema de destino, permitindo modelar
 * dinâmicas com dependências cruzadas entre compartimentos, como
 * modelos predador-presa ou transferências bidirecionalmente influenciadas.
 */
class FlowComplexo : public Flow_Impl {
public:

    /**
     * @brief Construtor padrão da classe FlowComplexo.
     */
    FlowComplexo();

    /**
     * @brief Construtor parametrizado da classe FlowComplexo.
     *
     * @param name Nome do fluxo.
     * @param source Ponteiro para o sistema de origem.
     * @param target Ponteiro para o sistema de destino.
     */
    FlowComplexo(
        const string& name,
        System* source,
        System* target
    );

    /**
     * @brief Construtor de cópia da classe FlowComplexo.
     *
     * @param other Objeto FlowComplexo a ser copiado.
     */
    FlowComplexo(
        const FlowComplexo& other
    );

    /**
     * @brief Destrutor virtual da classe FlowComplexo.
     */
    virtual ~FlowComplexo();

    /**
     * @brief Operador de atribuição da classe FlowComplexo.
     *
     * @param other Objeto FlowComplexo a ser atribuído.
     * @return Referência para o objeto atual.
     */
    FlowComplexo& operator=(
        const FlowComplexo& other
    );

    /**
     * @brief Executa o cálculo do fluxo complexo.
     *
     * Calcula a quantidade transferida entre os sistemas com base em
     * uma equação que combina os valores do sistema de origem e do
     * sistema de destino, modelando interações mais elaboradas entre
     * os compartimentos do modelo.
     *
     * @return Valor calculado pelo fluxo complexo.
     */
    double execute() override;
};

#endif