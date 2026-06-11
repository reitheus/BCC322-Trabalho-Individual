/**
 * @file unit_System.cpp
 * @brief Implementação dos testes unitários da classe System.
 *
 * Contém as implementações de cada função de teste unitário
 * declarada em unit_System.h, verificando o comportamento
 * da classe System_Impl para construção, destruição e
 * manipulação de valores.
 */

#include "unit_System.h"
#include <assert.h>
#include "..\..\include\system_impl.h"

void unit_System_constructor(void) {
    System_Impl s1("System1", 0);
    assert(s1.getValue() == 0);

    System_Impl s2("System2", 10);
    assert(s2.getValue() == 10);
}

void unit_System_destructor(void) {}

void unit_System_getValue(void) {
    System_Impl s("System", 10);
    assert(s.getValue() == 10);
}

void unit_System_setValue(void) {
    System_Impl s("System", 0);
    s.setValue(100);
    assert(s.getValue() == 100);
}

void run_unit_tests_System(void) {
    unit_System_constructor();
    unit_System_destructor();
    unit_System_getValue();
    unit_System_setValue();
    printf("System: All tests passed!\n");
}