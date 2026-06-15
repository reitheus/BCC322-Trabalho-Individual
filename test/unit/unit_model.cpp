/**
 * @file unit_Model.cpp
 * @brief Implementação dos testes unitários da classe Model.
 *
 * Contém uma classe de fluxo concreta auxiliar (FlowTest) utilizada
 * exclusivamente nos testes, além das implementações de cada função
 * de teste unitário declarada em unit_Model.h.
 */

#include "unit_Model.h"

#include <assert.h>

#include "../../include/model_impl.h"
#include "../../include/system_impl.h"
#include "../../include/flow_impl.h"

 /**
  * @brief Implementação concreta de Flow_Impl utilizada nos testes do Model.
  *
  * Classe auxiliar de teste que herda de Flow_Impl e fornece uma
  * implementação trivial de execute(), retornando sempre 1.0.
  * Permite testar a lógica de execução do Model sem depender de
  * uma equação de fluxo real.
  */
class FlowTest : public Flow_Impl {
public:
    /**
     * @brief Construtor padrão de FlowTest.
     */
    FlowTest() : Flow_Impl() {}

    /**
     * @brief Construtor parametrizado de FlowTest.
     *
     * @param name Nome do fluxo.
     * @param source Ponteiro para o sistema de origem.
     * @param target Ponteiro para o sistema de destino.
     */
    FlowTest(string name, System* source, System* target) : Flow_Impl(name, source, target) {}

    /**
     * @brief Implementação trivial de execute() para fins de teste.
     *
     * @return Sempre retorna 1.0.
     */
    double execute() override {
        return 1.0;
    }
};

void unit_Model_constructor(void) {
    Model_Impl model;

    System_Impl s1("S1", 100.0);
    System_Impl s2("S2", 0.0);

    FlowTest f1("F1", &s1, &s2);

    model.add(&s1);
    model.add(&s2);
    model.add(&f1);

    model.run(0, 1);

    assert(s1.getValue() == 99.0);
    assert(s2.getValue() == 1.0);
}

void unit_Model_destructor(void) {}

void unit_Model_addSystem(void) {
    Model_Impl model;

    System_Impl s1("S1", 100.0);
    System_Impl s2("S2", 0.0);

    FlowTest f1("F1", &s1, &s2);

    model.add(&s1);
    model.add(&s2);
    model.add(&f1);

    model.run(0, 1);

    assert(s1.getValue() == 99.0);
    assert(s2.getValue() == 1.0);
}

void unit_Model_addFlow(void) {
    Model_Impl model;

    System_Impl s1("S1", 100.0);
    System_Impl s2("S2", 0.0);

    FlowTest f1("F1", &s1, &s2);

    model.add(&s1);
    model.add(&s2);

    model.run(0, 1);

    assert(s1.getValue() == 100.0);
    assert(s2.getValue() == 0.0);

    model.add(&f1);

    model.run(0, 1);

    assert(s1.getValue() == 99.0);
    assert(s2.getValue() == 1.0);
}

void unit_Model_run(void) {
    Model_Impl model;

    System_Impl s1("S1", 100.0);
    System_Impl s2("S2", 0.0);

    FlowTest f1("F1", &s1, &s2);

    model.add(&s1);
    model.add(&s2);
    model.add(&f1);

    model.run(0, 10);

    assert(s1.getValue() == 90.0);
    assert(s2.getValue() == 10.0);
}

void unit_Model_showModel(void) {
    Model_Impl model;

    System_Impl s1("S1", 100.0);
    System_Impl s2("S2", 0.0);

    FlowTest f1("F1", &s1, &s2);

    model.add(&s1);
    model.add(&s2);
    model.add(&f1);

    model.showModel();

    assert(true);
}

void run_unit_tests_Model(void) {
    unit_Model_constructor();
    unit_Model_destructor();
    unit_Model_addSystem();
    unit_Model_addFlow();
    unit_Model_run();
    //unit_Model_showModel();
    printf("Model: All tests passed!\n");
}