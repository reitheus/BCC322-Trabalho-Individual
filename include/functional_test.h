#ifndef FUNCTIONAL_TESTS_H
#define FUNCTIONAL_TESTS_H

#include <assert.h>
#include <math.h>

/**
 * @brief Executa o teste funcional do modelo exponencial.
 *
 * Verifica se o comportamento do fluxo exponencial
 * produz os resultados esperados durante a simulação.
 */
void exponentialFuncionalTest();

/**
 * @brief Executa o teste funcional do modelo logístico.
 *
 * Verifica se o comportamento do fluxo logístico
 * produz os resultados esperados durante a simulação.
 */
void logisticalFuncionalTest();

/**
 * @brief Executa o teste funcional do modelo complexo.
 *
 * Verifica se o comportamento do modelo complexo
 * produz os resultados esperados durante a simulação.
 */
void complexFuncionalTest();

#endif