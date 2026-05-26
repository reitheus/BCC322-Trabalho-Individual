#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

/**
 * @brief Classe responsável por representar um sistema.
 *
 * Um sistema armazena um valor que pode ser alterado
 * durante a execução da simulação.
 */
class System {
private:

    /**
     * @brief Valor armazenado pelo sistema.
     */
    double value;

    /**
     * @brief Nome do sistema.
     */
    string name;

public:

    /**
     * @brief Construtor padrão da classe System.
     */
    System();

    /**
     * @brief Construtor da classe System.
     *
     * @param name Nome do sistema.
     * @param value Valor inicial do sistema.
     */
    System(const string& name, double value);

    /**
     * @brief Destrutor virtual da classe System.
     */
    virtual ~System();

    // Métodos da UML

    /**
     * @brief Retorna o nome do sistema.
     *
     * @return Nome do sistema.
     */
    string getName() const;

    /**
     * @brief Define o nome do sistema.
     *
     * @param name Novo nome do sistema.
     */
    void setName(const string& name);

    /**
     * @brief Retorna o valor atual do sistema.
     *
     * @return Valor armazenado no sistema.
     */
    double getValue() const;

    /**
     * @brief Define o valor do sistema.
     *
     * @param value Novo valor do sistema.
     */
    void setValue(double value);

private:

    /**
     * @brief Construtor de cópia privado.
     *
     * Impede cópia da classe System.
     *
     * @param other Outro objeto System.
     */
    System(const System& other);

    /**
     * @brief Operador de atribuição privado.
     *
     * Impede atribuição entre objetos System.
     *
     * @param other Outro objeto System.
     * @return Referência para o próprio objeto.
     */
    System& operator=(const System& other);
};

#endif