/**
 * @file functional_test.cpp
 * @brief Implementação dos testes funcionais do simulador.
 *
 * Este arquivo contém os testes funcionais que verificam se os
 * resultados produzidos pela simulação correspondem aos valores
 * analíticos esperados para cada modelo:
 * - Exponencial
 * - Logístico
 * - Complexo
 *
 * A comparação entre valores de ponto flutuante é feita com uma
 * margem de tolerância de 0.0001 para evitar erros de precisão numérica.
 */

#include <iostream>
#include "functional_test.h"

using namespace std;

/**
 * @brief Compara dois números de ponto flutuante com margem de tolerância.
 *
 * Utiliza uma margem de erro de 0.0001 para evitar falhas causadas
 * por imprecisões de representação em ponto flutuante.
 *
 * @param a Primeiro valor a comparar.
 * @param b Segundo valor a comparar.
 * @return true se a diferença absoluta entre @p a e @p b for menor que 0.0001.
 * @return false caso contrário.
 */
bool floatingPointComparison(double a, double b) {
    return fabs(a - b) < 0.0001;
}

/// Teste Funcional Exponecial
void exponentialFuncionalTest() {

    cout << endl;
    cout << "===== TESTE EXPONENCIAL =====" << endl;


    Model_Handle model("Modelo 1");

    System& pop1 = model.createSystem("pop1", 100.0);
    System& pop2 = model.createSystem("pop2", 0.0);
    model.createFlow<FlowExponencial>("Exponencial", &pop1, &pop2);

    cout << endl;
    cout << "ANTES:" << endl;
    //model.showModel();

    model.run(0, 100);

    cout << endl;
    cout << "DEPOIS:" << endl;
    //model.showModel();

    assert(floatingPointComparison(pop1.getValue(), 36.6032) == true);
    assert(floatingPointComparison(pop2.getValue(), 63.3968) == true);
    cout << "Exponential functional test approved." << endl;



}

/// Teste Funcional Logistico
void logisticalFuncionalTest() {

    cout << endl;
    cout << "===== TESTE LOGISTICO =====" << endl;

    Model_Handle model("Modelo 2");

    System& pop1 = model.createSystem("P", 100.0);
    System& pop2 = model.createSystem("Pmax", 10.0);
    model.createFlow<FlowLogistico>("Logistic", &pop1, &pop2);

    cout << endl;
    cout << "ANTES:" << endl;
    //model.showModel();

    model.run(0, 100);

    cout << endl;
    cout << "DEPOIS:" << endl;
    //model.showModel();

    assert(floatingPointComparison(pop1.getValue(), 88.2167) == true);
    assert(floatingPointComparison(pop2.getValue(), 21.7833) == true);
    cout << "Logistic functional test approved." << endl;

}

/// Teste Funcional Complexo

void complexFuncionalTest() {

    cout << endl;
    cout << "===== TESTE COMPLEXO =====" << endl;

    Model_Handle model("model3");

    System& Q1 = model.createSystem("Q1", 100.0);
    System& Q2 = model.createSystem("Q2", 0.0);
    System& Q3 = model.createSystem("Q3", 100.0);
    System& Q4 = model.createSystem("Q4", 0.0);
    System& Q5 = model.createSystem("Q5", 0.0);


    model.createFlow<FlowComplexo>("f", &Q1, &Q2);
    model.createFlow<FlowComplexo>("g", &Q1, &Q3);
    model.createFlow<FlowComplexo>("r", &Q2, &Q5);
    model.createFlow<FlowComplexo>("t", &Q2, &Q3);
    model.createFlow<FlowComplexo>("u", &Q3, &Q4);
    model.createFlow<FlowComplexo>("v", &Q4, &Q1);

    cout << endl;
    cout << "ANTES:" << endl;
    //model.showModel();

    model.run(0, 100);

    cout << endl;
    cout << "DEPOIS:" << endl;
    //model.showModel();

    assert(floatingPointComparison(Q1.getValue(), 31.8513) == true);

    assert(floatingPointComparison(Q2.getValue(), 18.4004) == true);

    assert(floatingPointComparison(Q3.getValue(), 77.1143) == true);

    assert(floatingPointComparison(Q4.getValue(), 56.1728) == true);

    assert(floatingPointComparison(Q5.getValue(), 16.4612) == true);


}