#ifndef FLOW_H
#define FLOW_H

#include <string>

using namespace std;

class System;

/**
 * @file flow.h
 * @brief Declaração da interface abstrata Flow.
 */

 /**
  * @brief Interface abstrata que representa um fluxo entre dois sistemas.
  *
  * A classe Flow define a interface para os fluxos de um modelo de
  * dinâmica de sistemas. Um fluxo conecta dois sistemas (origem e destino)
  * e define uma equação que determina a quantidade transferida por unidade
  * de tempo. Subclasses devem implementar o método execute().
  */
class Flow {
public:

    /**
     * @brief Destrutor virtual da classe Flow.
     */
    virtual ~Flow() = default;

    /**
     * @brief Retorna o nome do fluxo.
     *
     * @return Nome do fluxo.
     */
    virtual string getName() const = 0;

    /**
     * @brief Define o nome do fluxo.
     *
     * @param name Novo nome do fluxo.
     */
    virtual void setName(const string& name) = 0;

    /**
     * @brief Retorna o sistema de origem do fluxo.
     *
     * @return Ponteiro para o sistema de origem.
     */
    virtual System* getSource() const = 0;

    /**
     * @brief Define o sistema de origem do fluxo.
     *
     * @param source Ponteiro para o novo sistema de origem.
     */
    virtual void setSource(System* source) = 0;

    /**
     * @brief Retorna o sistema de destino do fluxo.
     *
     * @return Ponteiro para o sistema de destino.
     */
    virtual System* getTarget() const = 0;

    /**
     * @brief Define o sistema de destino do fluxo.
     *
     * @param target Ponteiro para o novo sistema de destino.
     */
    virtual void setTarget(System* target) = 0;

    // Método abstrato
    /**
     * @brief Executa o cálculo do fluxo para um instante de tempo.
     *
     * Método puramente virtual implementado pelas subclasses. Calcula
     * a quantidade a ser transferida do sistema de origem para o sistema
     * de destino com base na equação específica do fluxo.
     *
     * @return Valor calculado pelo fluxo.
     */
    virtual double execute() = 0;
};

#endif