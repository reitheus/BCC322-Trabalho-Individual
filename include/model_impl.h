#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H

/**
 * @file model_impl.h
 * @brief Declaração do Body (Model_Impl) e do Handle (Model) do padrão Handle-Body.
 *
 * Ambas as classes residem neste arquivo:
 *  - Model_Impl  →  Body concreto; armazena sistemas e fluxos, executa a simulação.
 *  - Model       →  Handle público; delega todas as operações a Model_Impl via pImpl_.
 */

#include <vector>
#include <string>
#include "handleBodySemDebug.h"
#include "model.h"
#include "system_impl.h"
#include "flow_impl.h"
using namespace std;

///Classe Model_Body
/**
 * @brief Body concreto que representa um modelo de dinâmica de sistemas.
 *
 * Armazena vetores de ponteiros para System_Impl e Flow_Impl, executa a
 * simulação de forma síncrona (todos os fluxos calculados antes de qualquer
 * atualização) e mantém um registro estático de todas as instâncias.
 */
class Model_Body : public Body {
protected:

    vector<System*> systems; /// Estoques do modelo.
    vector<Flow*> flows;   /// Fluxos do modelo.

    static vector<Model_Body*> models; /// Registro global de instâncias.

public:

    // Forma canônica
    /**
     * @brief Construtor padrão da classe Model.
     */
    Model_Body();

    /**
     * @brief Construtor parametrizado.
     *
     * @param id Identificador único do modelo.
     */
    Model_Body(const string& id);

    /**
     * @brief Construtor de cópia.
     *
     * @param other Objeto a ser copiado.
     */
    Model_Body(const Model_Body& other);

    Model_Body& operator=(const Model_Body& other);

    /**
     * @brief Destrutor virtual.
     *
     * Destrói os sistemas e fluxos internos e remove a instância
     * do registro estático.
     */
    virtual ~Model_Body();

    /**
     * @brief Adiciona um fluxo ao final do vetor de fluxos.
     *
     * @param f Ponteiro para o Body do fluxo.
     */
    void add(Flow* f);

    /**
     * @brief Insere um fluxo em posição específica (1-indexada).
     *
     * @param f Ponteiro para o Body do fluxo.
     * @param i Posição de inserção.
     */
    void add(Flow* f, int i);

    /**
     * @brief Adiciona um sistema ao vetor de sistemas.
     *
     * @param s Ponteiro para o Body do sistema.
     */
    void add(System* s);

    /**
     * @brief Cria e registra um sistema no modelo.
     *
     * @param id    Nome/identificador do sistema.
     * @param value Valor inicial.
     * @return Referência para o Handle do sistema criado.
     */
    System_Handle& createSystem(const string& id, double value);

    bool deleteSystem(System& s); /// Remove um sistema do modelo (stub).
    bool deleteFlow(Flow& f);     /// Remove um fluxo do modelo (stub).

    /**
     * @brief Define o sistema de origem de um fluxo.
     *
     * @param f Fluxo a configurar.
     * @param s Sistema de origem.
     */
    void setSource(Flow&, System&);

    /**
     * @brief Define o sistema de destino de um fluxo.
     *
     * @param f Fluxo a configurar.
     * @param s Sistema de destino.
     */
    void setTarget(Flow&, System&);

    void clearSource(Flow& f); /// Remove o source de um fluxo (nullptr).
    void clearTarget(Flow& f); /// Remove o target de um fluxo (nullptr).

    /**
    * @brief Executa a simulação no intervalo [t_init, t_final).
    *
    * Passo síncrono: todos os fluxos são calculados com os valores atuais
    * antes de qualquer atualização dos sistemas.
    *
    * @param t_init  Tempo inicial (inclusive).
    * @param t_final Tempo final (exclusive).
    * @return true se concluído com sucesso.
    */
    bool run(int t_init, int t_final);

    /**
     * @brief Exibe no console os sistemas e fluxos do modelo.
     */
    void showModel() const;

    string id_; ///< Identificador do modelo.

};

//=====================================================================
///Classe Model_Handle
/**
 * @brief Handle público que representa um modelo de dinâmica de sistemas.
 *
 * Mantém um ponteiro (pImpl_) para um Model_Impl e delega todas as
 * operações a ele. Fornece o método template createFlow<T>() para
 * instanciar qualquer subclasse concreta de Flow_Impl.
 *
 * Uso típico:
 * @code
 *   Model m("populacao");
 *   System& pop  = m.createSystem("populacao", 100.0);
 *   Flow&   nasc = m.createFlow<NascimentoFlow>("nascimento", &pop, nullptr);
 *   m.run(0, 10);
 * @endcode
 */
class Model_Handle : public Model,public Handle<Model_Body> {
public:
    /**
     * @brief Construtor padrão.
     */
    Model_Handle();

    /**
     * @brief Construtor parametrizado.
     *
     * @param id Identificador do modelo.
     */
    Model_Handle(const string& id);

    /**
     * @brief Construtor de cópia.
     *
     * Compartilha o mesmo Body com o Handle copiado.
     *
     * @param other Modelo a ser copiado.
     */
    Model_Handle(const Model_Handle& other);

    /**
     * @brief Destrutor virtual.
     */
    virtual ~Model_Handle();

    /**
     * @brief Operador de atribuição.
     *
     * @param other Modelo a ser atribuído.
     * @return Referência para o objeto atual.
     */
    Model_Handle& operator=(const Model_Handle& other);

    /**
     * @brief Cria e registra um sistema no modelo (delegado ao Body).
     *
     * @param id    Nome/identificador do sistema.
     * @param value Valor inicial.
     * @return Referência para o Handle do sistema criado.
     */
    System_Handle& createSystem(const string& id, double value);

    /**
     * @brief Cria e adiciona um fluxo concreto ao modelo.
     *
     * Método template que instancia qualquer subclasse de Flow_Impl,
     * configura source/target e registra o Body no Model_Impl.
     * Retorna um Flow (Handle) que envolve o Body criado.
     *
     * @tparam T_FLOW_IMPL Subclasse concreta de Flow_Impl com execute() definido.
     * @param id     Identificador do fluxo.
     * @param source Ponteiro para o sistema de origem (padrão nullptr).
     * @param target Ponteiro para o sistema de destino (padrão nullptr).
     * @return Referência para o Handle Flow recém-criado.
     */
    template <typename T_FLOW_IMPL>
    Flow_Handle& createFlow(
        const string& id,
        System* source = nullptr,
        System* target = nullptr) {
        T_FLOW_IMPL* body = new T_FLOW_IMPL(id, source, target);
        Flow_Handle* handle = new Flow_Handle(body); 
        pImpl_->add(handle);
        return *handle;
    }
    void add(System* system) override;
    void add(Flow* flow) override;
    bool deleteFlow(Flow& f) override; /// Remove um fluxo do modelo.
    bool deleteSystem(System& s) override; /// Remove um sistema do modelo.
    void setSource(Flow& f, System& s) override; /// Define o source de um fluxo.
    void setTarget(Flow& f, System& s) override; /// Define o target de um fluxo.
    void clearSource(Flow& f) override; /// Limpa o source de um fluxo.
    void clearTarget(Flow& f) override; /// Limpa o target de um fluxo.
    bool run(int t_init, int t_final); /// Executa a simulação.
    void showModel() const; /// Exibe o estado do modelo.
};
#endif