/**
 * @file main.cpp
 * @brief Ponto de entrada dos testes funcionais do simulador.
 *
 * Este arquivo executa em sequência todos os testes funcionais
 * do simulador de sistemas dinâmicos: exponencial, logístico e complexo.
 * Cada teste verifica se os valores finais da simulação correspondem
 * aos resultados analíticos esperados.
 */

#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "../../include/functional_test.h"
#include "../../include/model_impl.h"
#include "../../include/system_impl.h"
#include "../../include/flow.h"

 /**
  * @brief Função principal dos testes funcionais.
  *
  * Executa os três testes funcionais do simulador em sequência:
  * - exponentialFuncionalTest(): verifica o modelo de crescimento exponencial.
  * - logisticalFuncionalTest(): verifica o modelo de crescimento logístico.
  * - complexFuncionalTest(): verifica o modelo com múltiplos sistemas e fluxos.
  *
  * @return 0 caso todos os testes sejam executados com sucesso.
  */
int main() {
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();

    return true;
}

#endif