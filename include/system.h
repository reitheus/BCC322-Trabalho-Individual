#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

/**
 * @file system.h
 * @brief Declaração da interface abstrata System.
 */

 /**
  * @brief Interface abstrata que representa um sistema em um modelo de simulação.
  *
  * A classe System define a interface para os compartimentos (estoques) de um
  * modelo de dinâmica de sistemas. Um sistema armazena um valor numérico que
  * é modificado ao longo do tempo pelos fluxos conectados a ele. Subclasses
  * devem fornecer implementação concreta para todos os métodos virtuais puros.
  */
class System {
public:

    /**
     * @brief Destrutor virtual da classe System.
     */
    virtual ~System() = default;

    /**
     * @brief Retorna o nome do sistema.
     *
     * @return Nome do sistema.
     */
    virtual string getName() const = 0;

    /**
     * @brief Define o nome do sistema.
     *
     * @param name Novo nome do sistema.
     */
    virtual void setName(const string& name) = 0;

    /**
     * @brief Retorna o valor atual armazenado no sistema.
     *
     * @return Valor do sistema.
     */
    virtual double getValue() const = 0;

    /**
     * @brief Define o valor armazenado no sistema.
     *
     * @param value Novo valor do sistema.
     */
    virtual void setValue(double value) = 0;
};

#endif