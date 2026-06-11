<<<<<<< HEAD
#ifndef FLOW_H
#define FLOW_H

#include <string>

using namespace std;

class System;

class Flow {
public:

    /**
     * @brief Destrutor virtual da classe Flow.
     */
    virtual ~Flow() = default;

    // Getters e setters
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
     * @brief Retorna o sistema de origem.
     *
     * @return Ponteiro para o sistema de origem.
     */
    virtual System* getSource() const = 0;

    /**
     * @brief Define o sistema de origem.
     *
     * @param source Novo sistema de origem.
     */
    virtual void setSource(System* source) = 0;

    /**
     * @brief Retorna o sistema de destino.
     *
     * @return Ponteiro para o sistema de destino.
     */
    virtual System* getTarget() const = 0;

    /**
     * @brief Define o sistema de destino.
     *
     * @param target Novo sistema de destino.
     */
    virtual void setTarget(System* target) = 0;


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

>>>>>>> 9dbda6a123201c6dc76107ff8c4ed0c25a907394
#endif