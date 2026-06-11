#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

/**
 * @file unit_Flow.h
 * @brief Declaração dos testes unitários da classe Flow.
 *
 * Este arquivo contém os protótipos das funções de teste unitário
 * responsáveis por verificar individualmente cada método da classe
 * Flow e sua implementação concreta Flow_Impl.
 */

 /**
  * @brief Testa o construtor parametrizado da classe Flow.
  *
  * Verifica se, ao criar um fluxo com nome, sistema de origem e sistema
  * de destino, os atributos são corretamente inicializados.
  */
void unit_Flow_constructor(void);

/**
 * @brief Testa o destrutor da classe Flow.
 *
 * Verifica se o objeto é destruído sem erros ou vazamentos de memória.
 */
void unit_Flow_destructor(void);

/**
 * @brief Testa o método getName() da classe Flow.
 *
 * Verifica se o nome retornado corresponde ao valor definido na
 * construção do objeto.
 */
void unit_Flow_getName(void);

/**
 * @brief Testa o método setName() da classe Flow.
 *
 * Verifica se o nome do fluxo é atualizado corretamente após
 * a chamada de setName().
 */
void unit_Flow_setName(void);

/**
 * @brief Testa o método getSource() da classe Flow.
 *
 * Verifica se o ponteiro para o sistema de origem retornado
 * corresponde ao sistema definido na construção do objeto.
 */
void unit_Flow_getSource(void);

/**
 * @brief Testa o método setSource() da classe Flow.
 *
 * Verifica se o sistema de origem é atualizado corretamente após
 * a chamada de setSource().
 */
void unit_Flow_setSource(void);

/**
 * @brief Testa o método getTarget() da classe Flow.
 *
 * Verifica se o ponteiro para o sistema de destino retornado
 * corresponde ao sistema definido na construção do objeto.
 */
void unit_Flow_getTarget(void);

/**
 * @brief Testa o método setTarget() da classe Flow.
 *
 * Verifica se o sistema de destino é atualizado corretamente após
 * a chamada de setTarget().
 */
void unit_Flow_setTarget(void);

/**
 * @brief Testa o método execute() da classe Flow.
 *
 * Verifica se o valor retornado por execute() corresponde ao
 * resultado esperado para a equação do fluxo de teste.
 */
void unit_Flow_execute(void);

/**
 * @brief Executa todos os testes unitários da classe Flow em sequência.
 *
 * Chama cada função de teste unitário da classe Flow e exibe uma
 * mensagem de confirmação caso todos sejam aprovados.
 */
void run_unit_tests_Flow(void);

#endif