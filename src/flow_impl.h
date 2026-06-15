#ifndef FLOW_IMPL_H
#define FLOW_IMPL_H

#include <string>
#include "../include/flow.h"
#include "system_impl.h"
using namespace std;

class System;

class Flow_Impl : public Flow {
protected:
    string name;
    System* source;
    System* target;

public:

    // Forma canônica
    Flow_Impl();

    /**
     * @brief Construtor parametrizado da classe Flow.
     *
     * @param name Nome do fluxo.
     * @param source Sistema de origem.
     * @param target Sistema de destino.
     */
    Flow_Impl(const string& name,
              System* source,
              System* target);

    /**
     * @brief Construtor de cópia da classe Flow.
     *
     * @param other Outro objeto Flow.
     */
    Flow_Impl(const Flow_Impl& other);

    /**
     * @brief Destrutor da classe Flow.
     */
    virtual ~Flow_Impl();

    /**
     * @brief Operador de atribuição da classe Flow.
     *
     * Copia os atributos de outro fluxo.
     *
     * @param other Outro objeto Flow.
     * @return Referência para o objeto atual.
     */
    Flow_Impl& operator=(const Flow_Impl& other);

    // Getters e setters
    /**
     * @brief Retorna o nome do fluxo.
     *
     * @return Nome do fluxo.
     */
    string getName() const;

    /**
     * @brief Define o nome do fluxo.
     *
     * @param name Novo nome do fluxo.
     */
    void setName(const string& name);

    /**
     * @brief Retorna o sistema de origem.
     *
     * @return Ponteiro para o sistema de origem.
     */
    System* getSource() const;

    /**
     * @brief Define o sistema de origem.
     *
     * @param source Novo sistema de origem.
     */
    void setSource(System* source);

    /**
     * @brief Retorna o sistema de destino.
     *
     * @return Ponteiro para o sistema de destino.
     */
    System* getTarget() const;

    /**
     * @brief Define o sistema de destino.
     *
     * @param target Novo sistema de destino.
     */
    void setTarget(System* target);


    // Método abstrato
    /**
     * @brief Executa o cálculo do fluxo.
     *
     * Método abstrato implementado pelas subclasses.
     *
     * @return Valor calculado pelo fluxo.
     */
    virtual double execute() = 0;

};
#endif