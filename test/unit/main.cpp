/**
 * @file main.cpp
 * @brief Ponto de entrada da suíte de testes unitários.
 *
 * Arquivo principal responsável por iniciar a execução dos testes
 * unitários do modelo de simulação. Por padrão, executa todos os
 * testes globais via run_unit_tests_globals(). As chamadas individuais
 * por módulo (System, Flow, Model) estão disponíveis e podem ser
 * habilitadas removendo os comentários correspondentes.
 */

#include "unit_tests.h"

 /**
  * @brief Função principal do executável de testes unitários.
  *
  * Invoca a suíte de testes unitários globais. As chamadas individuais
  * por módulo estão comentadas e podem ser ativadas conforme necessário
  * para depuração isolada de cada classe.
  *
  * @return 0 em caso de sucesso (todos os asserts aprovados).
  */
int main() {
    run_unit_tests_globals();

    return true;
}