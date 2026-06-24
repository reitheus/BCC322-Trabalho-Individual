/**
 * @file unit_tests.cpp
 * @brief Implementação da função orquestradora dos testes unitários globais.
 *
 * Contém a implementação de run_unit_tests_globals(), que centraliza
 * a execução de todos os testes unitários do projeto, chamando as
 * suítes de teste de cada classe individualmente.
 */

#include <assert.h>
#include "unit_tests.h"

void run_unit_tests_globals(void) {
    run_unit_tests_System();
    run_unit_tests_Flow();
    run_unit_tests_Model();
    run_unit_tests_HandleBody();
}