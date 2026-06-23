#ifndef UNIT_SYSTEM
#define UNIT_SYSTEM

/**
 * @file unit_System.h
 * @brief Declaração dos testes unitários da classe System.
 *
 * Este arquivo contém os protótipos das funções de teste unitário
 * responsáveis por verificar individualmente cada método da classe
 * System e sua implementação concreta System_Impl.
 */

#include "../../include/system_impl.h"

 /**
  * @brief Testa o construtor parametrizado da classe System.
  *
  * Verifica se, ao criar sistemas com valores iniciais distintos,
  * o valor armazenado corresponde ao informado na construção.
  */
void unit_System_constructor(void);

/**
 * @brief Testa o destrutor da classe System.
 *
 * Verifica se o objeto é destruído sem erros ou vazamentos de memória.
 */
void unit_System_destructor(void);

/**
 * @brief Testa o método getValue() da classe System.
 *
 * Verifica se o valor retornado corresponde ao valor definido
 * na construção do objeto.
 */
void unit_System_getValue(void);

/**
 * @brief Testa o método setValue() da classe System.
 *
 * Verifica se o valor do sistema é atualizado corretamente após
 * a chamada de setValue(), sendo refletido por uma chamada subsequente
 * a getValue().
 */
void unit_System_setValue(void);

void unit_System_getName();
void unit_System_setName();

/**
 * @brief Executa todos os testes unitários da classe System em sequência.
 *
 * Chama cada função de teste unitário da classe System e exibe uma
 * mensagem de confirmação caso todos sejam aprovados.
 */
void run_unit_tests_System(void);

#endif