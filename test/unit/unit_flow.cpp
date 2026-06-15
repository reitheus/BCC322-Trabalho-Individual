/**
 * @file unit_Flow.cpp
 * @brief Implementação dos testes unitários da classe Flow.
 *
 * Contém uma classe de fluxo concreta auxiliar (Flow_Test) utilizada
 * exclusivamente nos testes, além das implementações de cada função
 * de teste unitário declarada em unit_Flow.h.
 */

#include "unit_Flow.h"

#include <assert.h>
#include "../../include/system_impl.h"
#include "../../include/flow_impl.h"

 /**
  * @brief Implementação concreta de Flow_Impl utilizada nos testes unitários.
  *
  * Classe auxiliar de teste que herda de Flow_Impl e fornece uma
  * implementação trivial de execute(), retornando sempre 1.0.
  * Permite testar os métodos de Flow_Impl sem depender de uma
  * equação de fluxo real.
  */
class Flow_Test : public Flow_Impl {
public:
    /**
     * @brief Construtor padrão de Flow_Test.
     */
    Flow_Test() : Flow_Impl() {}

    /**
     * @brief Construtor parametrizado de Flow_Test.
     *
     * @param name Nome do fluxo.
     * @param source Ponteiro para o sistema de origem.
     * @param target Ponteiro para o sistema de destino.
     */
    Flow_Test(string name, System* source, System* target) : Flow_Impl(name, source, target) {}

    /**
     * @brief Implementação trivial de execute() para fins de teste.
     *
     * @return Sempre retorna 1.0.
     */
    double execute() override {
        return 1.0;
    }
};

void unit_Flow_constructor(void) {
    System_Impl s1("Source", 100);
    System_Impl s2("Target", 0);

    Flow_Test f1("Flow1", &s1, &s2);

    assert(f1.getName() == "Flow1");
    assert(f1.getSource() == &s1);
    assert(f1.getTarget() == &s2);
}

void unit_Flow_destructor(void) {}

void unit_Flow_getName(void) {
    System_Impl s1("Source", 100);
    System_Impl s2("Target", 0);

    Flow_Test f("Flow", &s1, &s2);

    assert(f.getName() == "Flow");
}

void unit_Flow_setName(void) {
    System_Impl s1("Source", 100);
    System_Impl s2("Target", 0);

    Flow_Test f("Flow", &s1, &s2);

    f.setName("NewFlow");

    assert(f.getName() == "NewFlow");
}

void unit_Flow_getSource(void) {
    System_Impl s1("Source", 100);
    System_Impl s2("Target", 0);

    Flow_Test f("Flow", &s1, &s2);

    assert(f.getSource() == &s1);
}

void unit_Flow_setSource(void) {
    System_Impl s1("Source1", 100);
    System_Impl s2("Source2", 50);
    System_Impl target("Target", 0);

    Flow_Test f("Flow", &s1, &target);

    f.setSource(&s2);

    assert(f.getSource() == &s2);
}

void unit_Flow_getTarget(void) {
    System_Impl s1("Source", 100);
    System_Impl s2("Target", 0);

    Flow_Test f("Flow", &s1, &s2);

    assert(f.getTarget() == &s2);
}

void unit_Flow_setTarget(void) {
    System_Impl source("Source", 100);
    System_Impl t1("Target1", 0);
    System_Impl t2("Target2", 50);

    Flow_Test f("Flow", &source, &t1);

    f.setTarget(&t2);

    assert(f.getTarget() == &t2);
}

void unit_Flow_execute(void) {
    System_Impl source("Source", 100);
    System_Impl target("Target", 0);

    Flow_Test f("Flow", &source, &target);

    assert(f.execute() == 1.0);
}

void run_unit_tests_Flow(void) {
    unit_Flow_constructor();
    unit_Flow_destructor();
    unit_Flow_getName();
    unit_Flow_setName();
    unit_Flow_getSource();
    unit_Flow_setSource();
    unit_Flow_getTarget();
    unit_Flow_setTarget();
    unit_Flow_execute();
    printf("Flow: All tests passed!\n");
}