#ifndef MODEL_H
#define MODEL_H

#include <vector>

using namespace std;

/**
 * @file model.h
 * @brief Declaração da interface abstrata Model.
 */

 // Forward declarations
class System;
class Flow;

/**
 * @brief Interface abstrata que representa um modelo de dinâmica de sistemas.
 *
 * A classe Model define a interface para um modelo de simulação composto por
 * sistemas (estoques) e fluxos (equações de transferência). O modelo é
 * responsável por gerenciar esses elementos e conduzir a simulação ao longo
 * de um intervalo de tempo discreto. Subclasses devem fornecer implementação
 * concreta para todos os métodos virtuais puros.
 */
class Model {
public:

    /**
     * @brief Destrutor virtual da classe Model.
     */
    virtual ~Model() = default;

    /**
     * @brief Adiciona um sistema ao modelo.
     *
     * @param s Ponteiro para o sistema a ser adicionado.
     */
    virtual void add(System* s) = 0;

    /**
     * @brief Adiciona um fluxo ao modelo.
     *
     * @param f Ponteiro para o fluxo a ser adicionado.
     */
    virtual void add(Flow* f) = 0;

    /**
     * @brief Executa a simulação do modelo no intervalo de tempo especificado.
     *
     * A cada passo de tempo, todos os fluxos são calculados com base nos
     * valores atuais dos sistemas, e os sistemas são atualizados em seguida.
     *
     * @param t_init Tempo inicial da simulação (inclusive).
     * @param t_final Tempo final da simulação (inclusive).
     * @return true se a execução foi concluída com sucesso; false caso contrário.
     */
    virtual bool run(int t_init, int t_final) = 0;

    /**
     * @brief Exibe no console as informações dos sistemas e fluxos do modelo.
     */
    virtual void showModel() const = 0;
};

#endif