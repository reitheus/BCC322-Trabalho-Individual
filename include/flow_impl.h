#ifndef FLOW_IMPL_H
#define FLOW_IMPL_H

/**
 * @file flow_impl.h
 * @brief Declaração do Body (Flow_Impl) e do Handle (Flow) do padrão Handle-Body.
 *
 * Ambas as classes residem neste arquivo:
 *  - Flow_Impl  →  Body abstrato; armazena nome, source e target do fluxo.
 *  - Flow       →  Handle público; delega todas as operações a Flow_Impl via pImpl_.
 *
 * @note Flow_Impl::execute() é puramente virtual. Para criar um fluxo concreto,
 *       derive uma subclasse de Flow_Impl implementando execute().
 *       O método template Model::createFlow<T>() instancia esse Body automaticamente.
 *
 * @note Flow herda de Handle<Flow_Impl>, mas como Flow_Impl é abstrato o
 *       construtor padrão de Handle<T> (que faz new T) não pode ser usado.
 *       Por isso Flow NÃO usa Handle<Flow_Impl> como base — em vez disso
 *       expõe pImpl_ diretamente e gerencia o ciclo de vida manualmente,
 *       igual ao que Handle faria, mas sem instanciar o Body no construtor.
 */

#include <string>
#include "handleBodySemDebug.h"
#include "flow.h"
#include "system.h"
using namespace std;

///Classe Flow_Body
/**
 * @brief Body abstrato que representa um fluxo entre dois sistemas.
 *
 * Herda de Body para participar do gerenciamento de referências do
 * padrão Handle-Body. O método execute() é puramente virtual e deve
 * ser implementado pelas subclasses concretas de fluxo.
 */
class Flow_Body : public Body {
protected:
    string  name;   /// Nome do fluxo.
    System* source; /// Ponteiro para o sistema de origem.
    System* target; /// Ponteiro para o sistema de destino.

public:

    // Forma canônica
    /**
     * @brief Construtor padrão.
     *
     * Inicializa com nome vazio e ponteiros nulos.
     */
    Flow_Body();

    /**
     * @brief Construtor parametrizado.
     *
     * @param name   Nome do fluxo.
     * @param source Ponteiro para o sistema de origem.
     * @param target Ponteiro para o sistema de destino.
     */
    Flow_Body(const string& name, System* source, System* target);

    /**
     * @brief Construtor de cópia.
     *
     * @param other Objeto a ser copiado.
     */
    Flow_Body(const Flow_Body& other);

    /**
     * @brief Destrutor da classe Flow.
     */
    virtual ~Flow_Body();

    /**
     * @brief Operador de atribuição.
     *
     * @param other Objeto a ser atribuído.
     * @return Referência para o objeto atual.
     */
    Flow_Body& operator=(const Flow_Body& other);

    // Getters e setters
    /**
     * @brief Retorna o nome do fluxo.
     *
     * @return Nome do fluxo.
     */
    string getName() const; /// Retorna o nome do fluxo.

    /**
     * @brief Define o nome do fluxo.
     *
     * @param name Novo nome do fluxo.
     */
    void setName(const string& name); /// Define o nome do fluxo.

    /**
     * @brief Retorna o sistema de origem.
     *
     * @return Ponteiro para o sistema de origem.
     */
    System* getSource() const; /// Retorna o sistema de origem.

    /**
     * @brief Define o sistema de origem.
     *
     * @param source Novo sistema de origem.
     */
    void setSource(System* source); /// Define o sistema de origem.

    /**
     * @brief Retorna o sistema de destino.
     *
     * @return Ponteiro para o sistema de destino.
     */
    System* getTarget() const; /// Retorna o sistema de destino.

    /**
     * @brief Define o sistema de destino.
     *
     * @param target Novo sistema de destino.
     */
    void setTarget(System* target); /// Define o sistema de destino.

    /**
     * @brief Executa o cálculo do fluxo para um passo de tempo.
     *
     * Puramente virtual: implementado pelas subclasses concretas de fluxo.
     *
     * @return Valor a ser transferido entre os sistemas neste passo.
     */
    virtual double execute();

};

//====================================================================================
///Classe FLow_Handle
/**
 * @brief Handle público que representa um fluxo entre dois sistemas.
 *
 * Segue a semântica do padrão Handle-Body: mantém um ponteiro (pImpl_)
 * para um Flow_Impl concreto e gerencia seu ciclo de vida via contagem
 * de referências. Como Flow_Impl é abstrato, o Body nunca é instanciado
 * pelo construtor do Handle — ele é sempre fornecido de fora (via
 * Model::createFlow<T>()) e atribuído diretamente a pImpl_.
 *
 * O método execute() é puramente virtual aqui também: a subclasse
 * concreta de Flow_Impl é quem o implementa de fato.
 */
class Flow_Handle : public Flow, public Handle<Flow_Body>{
public:
    /**
     * @brief Construtor a partir de um Body concreto já existente.
     *
     * Recebe ownership do Flow_Impl apontado e incrementa sua referência.
     *
     * @param impl Ponteiro para o Body concreto (nunca nullptr).
     */
    explicit Flow_Handle(Flow_Body* impl);

    /**
     * @brief Construtor de cópia.
     *
     * Compartilha o mesmo Body, incrementando sua referência.
     *
     * @param other Fluxo a ser copiado.
     */
    Flow_Handle(const Flow_Handle& other);

    /**
     * @brief Destrutor virtual.
     *
     * Decrementa a referência do Body; Body se auto-destrói quando chega a zero.
     */
    virtual ~Flow_Handle();

    /**
     * @brief Operador de atribuição.
     *
     * @param other Fluxo a ser atribuído.
     * @return Referência para o objeto atual.
     */
    Flow_Handle& operator=(const Flow_Handle& other);

    //Getters e Setteres
    /**
     * @brief Retorna o nome do fluxo.
     *
     * @return Nome do fluxo.
     */
    string getName() const override; /// Retorna o nome (delegado ao Body).

    /**
     * @brief Define o nome do fluxo.
     *
     * @param name Novo nome do fluxo.
     */
    void setName(const string& name) override;  /// Define o nome (delegado ao Body).

    /**
    * @brief Retorna o sistema de origem.
    *
    * @return Ponteiro para o sistema de origem.
    */
    System* getSource() const override; /// Retorna o source (delegado ao Body).

    /**
     * @brief Define o sistema de origem.
     *
     * @param source Novo sistema de origem.
     */
    void setSource(System* source) override;    /// Define o source (delegado ao Body).

    /**
     * @brief Retorna o sistema de destino.
     *
     * @return Ponteiro para o sistema de destino.
     */
    System* getTarget() const override; /// Retorna o target (delegado ao Body).

    /**
     * @brief Define o sistema de destino.
     *
     * @param target Novo sistema de destino.
     */
    void setTarget(System* target) override;    /// Define o target (delegado ao Body).

    /**
     * @brief Executa o cálculo do fluxo (delegado ao Body).
     *
     * @return Valor calculado pelo fluxo.
     */
    double execute() override;

};

#endif