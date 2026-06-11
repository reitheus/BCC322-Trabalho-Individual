<<<<<<< HEAD
/**
 * @file main.cpp
 * @brief Arquivo principal dos testes funcionais.
 *
 * Este arquivo executa todos os testes funcionais
 * do simulador de sistemas dinâmicos.
 */

#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "../../include/functional_test.h"
#include "../../include/model.h"
#include "../../include/system.h"
#include "../../include/flow.h"

 /**
  * @brief Função principal dos testes funcionais.
  *
  * Executa:
  * - teste exponencial
  * - teste logístico
  * - teste complexo
  *
  * @return 0 caso os testes sejam executados com sucesso.
  */
int main() {

    exponentialFuncionalTest();

    logisticalFuncionalTest();

    complexFuncionalTest();

    return 0;
}

=======
<<<<<<< HEAD
#ifndef  MAIN_FUNCIONAL_TESTS

#define MAIN_FUNCIONAL_TESTS

#include "../../include/functional_test.h"

#include "../../include/model.h"

#include "../../include/system.h"

#include "../../include/flow.h"

int main() {

    exponentialFuncionalTest();

    logisticalFuncionalTest();

    complexFuncionalTest();

    return true;

}
=======
#ifndef  MAIN_FUNCIONAL_TESTS

#define MAIN_FUNCIONAL_TESTS

#include "../../include/functional_test.h"

#include "../../include/model.h"

#include "../../include/system.h"

#include "../../include/flow.h"

int main() {

    exponentialFuncionalTest();

    logisticalFuncionalTest();

    complexFuncionalTest();

    return 0;

}
>>>>>>> 9dbda6a123201c6dc76107ff8c4ed0c25a907394
>>>>>>> develop
#endif