#ifndef MODEL_H
#define MODEL_H

#include <vector>

using namespace std;

// Forward declaration
class System;
class Flow;

/**
 * @brief Classe responsável por representar um modelo de simulação.
 *
 * A classe Model armazena os sistemas e fluxos que compõem
 * um modelo de dinâmica de sistemas, sendo responsável
 * pela execução da simulação.
 */
class Model {
private:

    /**
     * @brief Vetor contendo os sistemas do modelo.
     */
    vector<System*> systems;

    /**
     * @brief Vetor contendo os fluxos do modelo.
     */
    vector<Flow*> flows;

public:

    /**
     * @brief Construtor padrão da classe Model.
     */
    Model();

    /**
     * @brief Destrutor virtual da classe Model.
     */
    virtual ~Model();


    // Métodos da UML

    /**
     * @brief Adiciona um sistema ao modelo.
     *
     * @param s Ponteiro para o sistema a ser adicionado.
     */
    void add(System* s);

    /**
     * @brief Adiciona um fluxo ao modelo.
     *
     * @param f Ponteiro para o fluxo a ser adicionado.
     */
    void add(Flow* f);


    /**
     * @brief Executa a simulação do modelo.
     *
     * @param t_init Tempo inicial da simulação.
     * @param t_final Tempo final da simulação.
     *
     * @return true caso a execução seja concluída com sucesso.
     * @return false caso ocorra falha na execução.
     */
    bool run(int t_init, int t_final);

    /**
     * @brief Exibe informações do modelo.
     */
    void showModel() const;

private:

    /**
     * @brief Construtor de cópia privado.
     *
     * Impede cópia da classe Model.
     *
     * @param other Outro objeto Model.
     */
    Model(const Model& other);

    /**
     * @brief Operador de atribuição privado.
     *
     * Impede atribuição entre objetos Model.
     *
     * @param other Outro objeto Model.
     * @return Referência para o próprio objeto.
     */
    Model& operator=(const Model& other);
};

#endif