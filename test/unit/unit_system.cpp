/**
 * @file unit_System.cpp
 * @brief Implementação dos testes unitários da classe System.
 *
 * Contém as implementações de cada função de teste unitário
 * declarada em unit_System.h, verificando o comportamento
 * da classe System_Impl para construção, destruição e
 * manipulação de valores.
 */

#include "unit_system.h"
#include <assert.h>


void unit_System_constructor(void) {
    System_Handle s1("System1", 0);

    assert(s1.getName() == "System1");
    assert(s1.getValue() == 0);

    System_Handle s2("System2", 10);

    assert(s1.getName() == "System2");
    assert(s2.getValue() == 10);
}

void unit_System_destructor(void) {}

void unit_System_getValue(void) {
    System_Handle s("System", 10);
    assert(s.getValue() == 10);
}

void unit_System_setValue(void) {
    System_Handle s("System", 0);
    s.setValue(100);
    assert(s.getValue() == 100);
}

void unit_System_getName(void) {
    System_Handle s("System", 10);
    assert(s.getName() == "System");
}

void unit_System_setName(void) {
    System_Handle s("System", 10);

    s.setName("NewSystem");

    assert(s.getName() == "NewSystem");
}

void run_unit_tests_System(void) {
    unit_System_constructor();
    unit_System_destructor();
    unit_System_getValue();
    unit_System_setValue();
    unit_System_getName();
    unit_System_setName();
    printf("System: All tests passed!\n");
}