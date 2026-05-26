#ifndef FLOWS_H
#define FLOWS_H

#include "flow.h"

/**
 * @brief Classe responsável pelo fluxo exponencial.
 *
 * Implementa um fluxo baseado em crescimento exponencial
 * entre sistemas.
 */
class FlowExponencial : public Flow {
public:

    /**
     * @brief Construtor padrão da classe FlowExponencial.
     */
    FlowExponencial();

    /**
     * @brief Construtor parametrizado da classe FlowExponencial.
     *
     * @param name Nome do fluxo.
     * @param source Sistema de origem.
     * @param target Sistema de destino.
     */
    FlowExponencial(
        const string& name,
        System* source,
        System* target
    );

    /**
     * @brief Construtor de cópia da classe FlowExponencial.
     *
     * @param other Outro objeto FlowExponencial.
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
     * @param other Outro objeto FlowExponencial.
     * @return Referência para o objeto atual.
     */
    FlowExponencial& operator=(
        const FlowExponencial& other
        );

    /**
     * @brief Executa o cálculo do fluxo exponencial.
     *
     * @return Valor calculado pelo fluxo.
     */
    double execute() override;
};


/**
 * @brief Classe responsável pelo fluxo logístico.
 *
 * Implementa um fluxo baseado em crescimento logístico
 * entre sistemas.
 */
class FlowLogistico : public Flow {
public:

    /**
     * @brief Construtor padrão da classe FlowLogistico.
     */
    FlowLogistico();

    /**
     * @brief Construtor parametrizado da classe FlowLogistico.
     *
     * @param name Nome do fluxo.
     * @param source Sistema de origem.
     * @param target Sistema de destino.
     */
    FlowLogistico(
        const string& name,
        System* source,
        System* target
    );

    /**
     * @brief Construtor de cópia da classe FlowLogistico.
     *
     * @param other Outro objeto FlowLogistico.
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
     * @param other Outro objeto FlowLogistico.
     * @return Referência para o objeto atual.
     */
    FlowLogistico& operator=(
        const FlowLogistico& other
        );

    /**
     * @brief Executa o cálculo do fluxo logístico.
     *
     * @return Valor calculado pelo fluxo.
     */
    double execute() override;
};


/**
 * @brief Classe responsável pelo fluxo complexo.
 *
 * Implementa um fluxo com múltiplas interações
 * entre sistemas.
 */
class FlowComplexo : public Flow {
public:

    /**
     * @brief Construtor padrão da classe FlowComplexo.
     */
    FlowComplexo();

    /**
     * @brief Construtor parametrizado da classe FlowComplexo.
     *
     * @param name Nome do fluxo.
     * @param source Sistema de origem.
     * @param target Sistema de destino.
     */
    FlowComplexo(
        const string& name,
        System* source,
        System* target
    );

    /**
     * @brief Construtor de cópia da classe FlowComplexo.
     *
     * @param other Outro objeto FlowComplexo.
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
     * @param other Outro objeto FlowComplexo.
     * @return Referência para o objeto atual.
     */
    FlowComplexo& operator=(
        const FlowComplexo& other
        );

    /**
     * @brief Executa o cálculo do fluxo complexo.
     *
     * @return Valor calculado pelo fluxo.
     */
    double execute() override;
};

#endif