#ifndef FUNCTIONAL_TESTS_H
#define FUNCTIONAL_TESTS_H

#include <assert.h>
#include <math.h>
#include "flows.h"
#include "../../include/model_impl.h"
#include "../../include/system_impl.h"

/**
 * @file functional_test.h
 * @brief Declaração dos testes funcionais dos modelos de simulação.
 *
 * Este arquivo contém os protótipos das funções de teste funcional
 * responsáveis por verificar o comportamento esperado dos modelos
 * exponencial, logístico e complexo após a execução da simulação.
 */

 /**
  * @brief Executa o teste funcional do modelo exponencial.
  *
  * Cria um modelo com dois sistemas e um fluxo exponencial,
  * executa a simulação por um intervalo de tempo pré-definido
  * e verifica, via assert, se os valores finais dos sistemas
  * correspondem aos resultados esperados analiticamente.
  */
void exponentialFuncionalTest();

/**
 * @brief Executa o teste funcional do modelo logístico.
 *
 * Cria um modelo com dois sistemas e um fluxo logístico,
 * executa a simulação por um intervalo de tempo pré-definido
 * e verifica, via assert, se os valores finais dos sistemas
 * correspondem aos resultados esperados analiticamente.
 */
void logisticalFuncionalTest();

/**
 * @brief Executa o teste funcional do modelo complexo.
 *
 * Cria um modelo com múltiplos sistemas e fluxos interligados,
 * executa a simulação por um intervalo de tempo pré-definido
 * e verifica, via assert, se os valores finais de cada sistema
 * correspondem aos resultados esperados.
 */
void complexFuncionalTest();

#endif