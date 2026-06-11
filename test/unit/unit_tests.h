#ifndef UNIT_TESTS
#define UNIT_TESTS

/**
 * @file unit_tests.h
 * @brief Declaração da função de entrada dos testes unitários globais.
 *
 * Este arquivo agrega os cabeçalhos de todos os módulos de teste
 * unitário (System, Flow e Model) e declara a função orquestradora
 * que os executa em sequência.
 */

#include "unit_System.h"
#include "unit_Flow.h"
#include "unit_Model.h"

 /**
  * @brief Executa todos os testes unitários do projeto em sequência.
  *
  * Chama run_unit_tests_System(), run_unit_tests_Flow() e
  * run_unit_tests_Model(), cobrindo os testes unitários de
  * todas as classes do modelo de simulação.
  */
void run_unit_tests_globals(void);

#endif