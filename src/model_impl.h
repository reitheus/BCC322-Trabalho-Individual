#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H

#include <vector>
#include "../include/model.h"
using namespace std;

// Forward declaration
class System;
class Flow;

/**
 * @brief Classe responsável por representar um modelo de simulação.
 *
 * A classe Model_Impl armazena os sistemas e fluxos que compõem
 * um modelo de dinâmica de sistemas, sendo responsável
 * pela execução da simulação.
 */
class Model_Impl : public Model {
protected:

    /**
     * @brief Vetor contendo os sistemas do modelo.
     */
    vector<System*> systems;

    /**
     * @brief Vetor contendo os fluxos do modelo.
     */
    vector<Flow*> flows;

    /**
     * @brief Vetor estático contendo todos os modelos criados.
     *
     * Armazena ponteiros para todas as instâncias de Model_Impl
     * criadas via createModel(), permitindo gerenciamento global dos modelos.
     */
    static vector<Model*> models;

public:

    /// Forma canônica
    /**
     * @brief Construtor padrão da classe Model.
     */
    Model_Impl(string);

    /**
     * @brief Construtor de cópia privado.
     *
     * Impede cópia da classe Model.
     *
     * @param other Outro objeto Model.
     */
    Model_Impl(const Model_Impl& other);

    /**
     * @brief Operador de atribuição privado.
     *
     * Impede atribuição entre objetos Model.
     *
     * @param other Outro objeto Model.
     * @return Referência para o próprio objeto.
     */
    Model_Impl& operator=(const Model_Impl& other);

    /**
     * @brief Destrutor virtual da classe Model.
     */
    virtual ~Model_Impl();

    /**
     * @brief Cria e registra uma nova instância de Model_Impl.
     *
     * Método estático de fábrica que instancia um Model_Impl com o
     * identificador fornecido, registra-o no vetor estático e o retorna.
     *
     * @param id Identificador único do modelo.
     * @return Referência para o modelo recém-criado.
     */
    static Model& createModel(string id);

    /**
     * @brief Cria e adiciona um sistema ao modelo.
     *
     * Instancia um System_Impl com o identificador e valor inicial
     * fornecidos, adiciona-o ao vetor interno e retorna a referência.
     *
     * @param id Identificador do sistema.
     * @param value Valor inicial do sistema.
     * @return Referência para o sistema recém-criado.
     */
    System& createSystem(string id, double);

    /**
     * @brief Remove um sistema do modelo.
     *
     * @param s Referência para o sistema a ser removido.
     * @return true se o sistema foi removido com sucesso; false caso contrário.
     */
    bool deleteSystem(System&);

    /**
     * @brief Remove um fluxo do modelo.
     *
     * @param f Referência para o fluxo a ser removido.
     * @return true se o fluxo foi removido com sucesso; false caso contrário.
     */
    bool deleteFlow(Flow&);

    /**
     * @brief Define o sistema de origem de um fluxo.
     *
     * Realiza cast para Flow_Impl e invoca setSource().
     *
     * @param f Referência para o fluxo a ser configurado.
     * @param s Referência para o sistema que será a origem.
     */
    void setSource(Flow&, System&);

    /**
     * @brief Define o sistema de destino de um fluxo.
     *
     * Realiza cast para Flow_Impl e invoca setTarget().
     *
     * @param f Referência para o fluxo a ser configurado.
     * @param s Referência para o sistema que será o destino.
     */
    void setTarget(Flow&, System&);

    /**
     * @brief Remove o sistema de origem de um fluxo, definindo-o como nulo.
     *
     * @param f Referência para o fluxo cujo source será limpo.
     */
    void clearSource(Flow&);

    /**
     * @brief Remove o sistema de destino de um fluxo, definindo-o como nulo.
     *
     * @param f Referência para o fluxo cujo target será limpo.
     */
    void clearTarget(Flow&);

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
     * @brief Registra um modelo no vetor estático interno.
     *
     * @param m Ponteiro para o modelo a ser registrado.
     */
    void add(Model*);

    /**
     * @brief Adiciona um fluxo ao final do vetor de fluxos.
     *
     * @param f Ponteiro para o fluxo a ser adicionado.
     */
    void add(Flow*);

    /**
     * @brief Adiciona um sistema ao vetor de sistemas.
     *
     * @param s Ponteiro para o sistema a ser adicionado.
     */
    void add(System*);

    /**
     * @brief Insere um fluxo em posição específica do vetor de fluxos.
     *
     * @param f Ponteiro para o fluxo a ser inserido.
     * @param i Posição de inserção (1-indexada).
     */
    void add(Flow*, int i);

public:
    /**
     * @brief Identificador único do modelo.
     */
    string id_;

};

#endif