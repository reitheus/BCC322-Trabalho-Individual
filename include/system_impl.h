#ifndef SYSTEM_IMPL_H
#define SYSTEM_IMPL_H

/**
 * @file system_impl.h
 * @brief Declaração do Body (System_Impl) e do Handle (System) do padrão Handle-Body.
 *
 * Ambas as classes residem neste arquivo:
 *  - System_Impl  →  Body concreto; armazena nome e valor do estoque.
 *  - System       →  Handle público; delega todas as operações a System_Impl via pImpl_.
 */

#include <string>
#include "handleBodySemDebug.h"
#include "system.h"

using namespace std;

///Classe System_body
/**
 * @brief Body concreto que representa um sistema (estoque) no simulador.
 *
 * Herda de Body para participar do gerenciamento de referências do
 * padrão Handle-Body. É instanciado e destruído exclusivamente pelo
 * Handle (System).
 */
class System_Body : public Body {
private:
    
    double value; ///< Valor numérico armazenado pelo sistema.
    string name; ///< Nome do sistema.

public:

    // Forma canônica
    /**
     * @brief Construtor padrão da classe System.
     */
    System_Body();

    /**
     * @brief Construtor da classe System.
     *
     * @param name Nome do sistema.
     * @param value Valor inicial do sistema.
     */
    System_Body(const string& name, double value);
private:
    /**
     * @brief Construtor de cópia privado.
     *
     * Impede cópia da classe System.
     *
     * @param other Outro objeto System.
     */
    System_Body(const System_Body& other);

    /**
     * @brief Operador de atribuição.
     *
     * @param other Objeto a ser atribuído.
     * @return Referência para o objeto atual.
     */
    System_Body& operator=(const System_Body& other);

public:
    /**
     * @brief Destrutor virtual da classe System.
     */
    virtual ~System_Body();

    //Getters e Setters
    /**
     * @brief Retorna o nome do sistema.
     *
     * @return Nome do sistema.
     */
    string getName() const; /// Retorna o nome do sistema.

    /**
     * @brief Define o nome do sistema.
     *
     * @param name Novo nome do sistema.
     */
    void setName(const string& name); /// Define o nome do sistema.

    /**
     * @brief Retorna o valor atual do sistema.
     *
     * @return Valor armazenado no sistema.
     */
    double getValue() const; /// Retorna o valor do sistema.

    /**
     * @brief Define o valor do sistema.
     *
     * @param value Novo valor do sistema.
     */
    void setValue(double value); /// Define o valor do sistema.

public:
    /**
    * @breif Indentificador único
    */
    string id_;

};

//===============================================================================================
/// Classe System_Handle
/**
 * @brief Handle público que representa um sistema (estoque) no simulador.
 *
 * Mantém um ponteiro (pImpl_) para um System_Impl e delega todas as
 * operações a ele. O ciclo de vida do Body é gerenciado automaticamente
 * pela contagem de referências herdada de Handle<System_Impl>.
 */
class System_Handle : public System, public Handle<System_Body> {
public:

    /**
     * @brief Construtor padrão da classe System.
     */
    System_Handle();

    System_Handle(System_Body* impl);

    /**
     * @brief Construtor da classe System.
     *
     * @param name Nome do sistema.
     * @param value Valor inicial do sistema.
     */
    System_Handle(const string& name, double value);

    /**
     * @brief Destrutor virtual da classe System.
     */
    virtual ~System_Handle();


    // Getters e Setters
    /**
     * @brief Retorna o valor atual do sistema.
     *
     * @return Valor armazenado no sistema.
     */
    double getValue() const override; ///< Retorna o valor (delegado ao Body).

    /**
     * @brief Retorna o nome do sistema.
     *
     * @return Nome do sistema.
     */
    string getName() const override; /// Retorna o nome (delegado ao Body).

    /**
     * @brief Define o nome do sistema.
     *
     * @param name Novo nome do sistema.
     */
    void setName(const string& name) override; /// Define o nome (delegado ao Body).

    /**
     * @brief Define o valor do sistema.
     *
     * @param value Novo valor do sistema.
     */
    void setValue(double value) override; ///< Define o valor (delegado ao Body).
};

#endif