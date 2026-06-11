#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

/**
 * @file unit_Model.h
 * @brief Declaração dos testes unitários da classe Model.
 *
 * Este arquivo contém os protótipos das funções de teste unitário
 * responsáveis por verificar individualmente cada método da classe
 * Model e sua implementação concreta Model_Impl.
 */

 /**
  * @brief Testa o construtor da classe Model.
  *
  * Cria um modelo, adiciona sistemas e um fluxo de teste, executa
  * a simulação por um passo e verifica se os valores dos sistemas
  * foram atualizados corretamente.
  */
void unit_Model_constructor(void);

/**
 * @brief Testa o destrutor da classe Model.
 *
 * Verifica se o objeto é destruído sem erros ou vazamentos de memória.
 */
void unit_Model_destructor(void);

/**
 * @brief Testa o método add(System*) da classe Model.
 *
 * Verifica se sistemas adicionados ao modelo participam corretamente
 * da simulação, tendo seus valores atualizados após a execução dos fluxos.
 */
void unit_Model_addSystem(void);

/**
 * @brief Testa o método add(Flow*) da classe Model.
 *
 * Verifica o comportamento do modelo com e sem fluxo adicionado:
 * sem fluxo os sistemas não se alteram; com fluxo a transferência
 * ocorre corretamente a cada passo de tempo.
 */
void unit_Model_addFlow(void);

/**
 * @brief Testa o método run() da classe Model.
 *
 * Executa a simulação por múltiplos passos de tempo e verifica se
 * os valores finais dos sistemas correspondem ao total acumulado
 * de transferências esperado.
 */
void unit_Model_run(void);

/**
 * @brief Testa o método showModel() da classe Model.
 *
 * Verifica se a exibição das informações do modelo é executada
 * sem erros. A correção visual da saída deve ser verificada manualmente.
 */
void unit_Model_showModel(void);

/**
 * @brief Executa todos os testes unitários da classe Model em sequência.
 *
 * Chama cada função de teste unitário da classe Model e exibe uma
 * mensagem de confirmação caso todos sejam aprovados.
 */
void run_unit_tests_Model(void);

#endif