#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "../src/flow_impl.h"

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
     * @brief Cria e registra uma nova instância de Model.
     *
     * Método estático de fábrica que instancia um Model_Impl,
     * registra-o no vetor estático de modelos e o retorna por referência.
     *
     * @param id Identificador único do modelo.
     * @return Referência para o modelo recém-criado.
     */
    static Model& createModel(string id = 0);

    /**
     * @brief Cria e adiciona um fluxo concreto ao modelo.
     *
     * Método template que instancia qualquer subclasse de Flow_Impl,
     * vincula os sistemas de origem e destino fornecidos e registra
     * o fluxo no modelo.
     *
     * @tparam T_FLOW_IMPL Tipo concreto do fluxo a ser criado (deve herdar de Flow_Impl).
     * @param id Identificador do fluxo.
     * @param source Ponteiro para o sistema de origem (opcional, padrão NULL).
     * @param target Ponteiro para o sistema de destino (opcional, padrão NULL).
     * @return Referência para o fluxo recém-criado.
     */
    template <typename T_FLOW_IMPL>
    Flow& createFlow(string id, System* source = NULL, System* target = NULL) {
        Flow* flow = new T_FLOW_IMPL(id, source, target);
        add(flow);
        return *flow;
    }

    /**
     * @brief Cria e adiciona um sistema ao modelo.
     *
     * Instancia um System_Impl com o identificador e valor inicial
     * fornecidos e o registra no modelo.
     *
     * @param id Identificador do sistema.
     * @param value Valor inicial do sistema.
     * @return Referência para o sistema recém-criado.
     */
    virtual System& createSystem(string id, double) = 0;

    /**
     * @brief Destrutor virtual da classe Model.
     */
    virtual ~Model() = default;

    /**
     * @brief Remove um fluxo do modelo.
     *
     * @param f Referência para o fluxo a ser removido.
     * @return true se o fluxo foi removido com sucesso; false caso contrário.
     */
    virtual bool deleteFlow(Flow&) = 0;

    /**
     * @brief Remove um sistema do modelo.
     *
     * @param s Referência para o sistema a ser removido.
     * @return true se o sistema foi removido com sucesso; false caso contrário.
     */
    virtual bool deleteSystem(System&) = 0;

    /**
     * @brief Define o sistema de origem de um fluxo.
     *
     * @param f Referência para o fluxo a ser configurado.
     * @param s Referência para o sistema que será a origem.
     */
    virtual void setSource(Flow&, System&) = 0;

    /**
     * @brief Define o sistema de destino de um fluxo.
     *
     * @param f Referência para o fluxo a ser configurado.
     * @param s Referência para o sistema que será o destino.
     */
    virtual void setTarget(Flow&, System&) = 0;

    /**
     * @brief Remove o sistema de origem de um fluxo, definindo-o como nulo.
     *
     * @param f Referência para o fluxo cujo source será limpo.
     */
    virtual void clearSource(Flow&) = 0;

    /**
     * @brief Remove o sistema de destino de um fluxo, definindo-o como nulo.
     *
     * @param f Referência para o fluxo cujo target será limpo.
     */
    virtual void clearTarget(Flow&) = 0;

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
protected:
    /**
     * @brief Registra um modelo no vetor estático interno de modelos.
     *
     * @param m Ponteiro para o modelo a ser registrado.
     */
    virtual void add(Model*) = 0;

    /**
     * @brief Adiciona um fluxo à lista interna do modelo.
     *
     * @param f Ponteiro para o fluxo a ser adicionado.
     */
    virtual void add(Flow*) = 0;
};

#endif