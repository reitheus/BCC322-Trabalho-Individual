#ifndef FLOW_H
#define FLOW_H

#include <string>

using namespace std;

class System;

/*
  @brief Classe abstrata responsável por representar um fluxo.
 
  A classe Flow define a estrutura básica de um fluxo
  em um modelo de dinâmica de sistemas, conectando
  um sistema de origem a um sistema de destino.
 */
class Flow {
protected:

    /*
      @brief Nome do fluxo.
     */
    string name;

    /*
      @brief Sistema de origem do fluxo.
     */
    System* source;

    /*
      @brief Sistema de destino do fluxo.
     */
    System* target;

public:

    // Forma canônica

    /*
      @brief Construtor padrão da classe Flow.
     */
    Flow();

    /*
      @brief Construtor parametrizado da classe Flow.
     
      @param name Nome do fluxo.
      @param source Sistema de origem.
      @param target Sistema de destino.
     */
    Flow(const string& name,
        System* source,
        System* target);

    /*
      @brief Destrutor virtual da classe Flow.
     */
    virtual ~Flow();

    // Getters e setters

    /*
      @brief Retorna o nome do fluxo.
     
      @return Nome do fluxo.
     */
    string getName() const;

    /*
      @brief Define o nome do fluxo.
     
      @param name Novo nome do fluxo.
     */
    void setName(const string& name);

    /*
      @brief Retorna o sistema de origem.
     
      @return Ponteiro para o sistema de origem.
     */
    System* getSource() const;

    /*
      @brief Define o sistema de origem.
     
      @param source Novo sistema de origem.
     */
    void setSource(System* source);

    /*
      @brief Retorna o sistema de destino.
     
      @return Ponteiro para o sistema de destino.
     */
    System* getTarget() const;

    /*
      @brief Define o sistema de destino.
     
      @param target Novo sistema de destino.
     */
    void setTarget(System* target);

    /*
      @brief Executa o cálculo do fluxo.
     
      Método abstrato implementado pelas subclasses.
     
      @return Valor calculado pelo fluxo.
     */
    virtual double execute() = 0;

private:

    /*
      @brief Operador de atribuição privado.
     
      Impede atribuição entre objetos Flow.
     
      @param other Outro objeto Flow.
      @return Referência para o objeto atual.
     */
    Flow& operator=(const Flow& other);

    /*
      @brief Construtor de cópia privado.
     
      Impede cópia da classe Flow.
     
      @param other Outro objeto Flow.
     */
    Flow(const Flow& other);
};

#endif