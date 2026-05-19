#include <iostream>

#include "../../include/model.h"
#include "../../include/system.h"
#include "../../include/flows.h"
#include "../../include/functional_test.h"

using namespace std;

bool floatingPointComparison(double a, double b){
    return fabs(a - b) < 0.0001;
}

//Teste exponencial

void exponentialFuncionalTest() {

    cout << endl;
    cout << "===== TESTE EXPONENCIAL ====="
         << endl;

    System pop1("pop1", 100.0);
    System pop2("pop2", 0.0);

    FlowExponencial flow(
        "Exponential",
        &pop1,
        &pop2
    );

    Model model;

    model.add(&pop1);
    model.add(&pop2);
    model.add(&flow);

    cout << endl;
    cout << "ANTES:" << endl;
    model.showModel();

    model.run(0, 100);

    cout << endl;
    cout << "DEPOIS:" << endl;
    model.showModel();

    assert (floatingPointComparison(pop1.getValue(), 36.6032) == true);
    assert (floatingPointComparison(pop2.getValue(), 63.3968) == true);
}


//Logistico

void logisticalFuncionalTest() {

    cout << endl;
    cout << "===== TESTE LOGISTICO ====="
         << endl;

    System pop1("P", 100.0);
    System pop2("Pmax", 10.0);

    FlowLogistico flow(
        "Logistic",
        &pop1,
        &pop2
    );

    Model model;

    model.add(&pop1);
    model.add(&pop2);
    model.add(&flow);

    cout << endl;
    cout << "ANTES:" << endl;
    model.showModel();

    model.run(0, 100);

    cout << endl;
    cout << "DEPOIS:" << endl;
    model.showModel();

    assert (floatingPointComparison(pop1.getValue(), 88.2167) == true);
    assert (floatingPointComparison(pop2.getValue(), 21.7833) == true);

}


//Complexo

void complexFuncionalTest() {

    cout << endl;
    cout << "===== TESTE COMPLEXO =====" << endl;


    System Q1("Q1", 100.0);
    System Q2("Q2", 0.0);
    System Q3("Q3", 100.0);
    System Q4("Q4", 0.0);
    System Q5("Q5", 0.0);


    FlowComplexo f(
        "f",
        &Q1,
        &Q2
    );

    FlowComplexo g(
        "g",
        &Q1,
        &Q3
    );

    FlowComplexo r(
        "r",
        &Q2,
        &Q5
    );

    FlowComplexo t(
        "t",
        &Q2,
        &Q3
    );

    FlowComplexo u(
        "u",
        &Q3,
        &Q4
    );

    FlowComplexo v(
        "v",
        &Q4,
        &Q1
    );



    Model model;

    model.add(&Q1);
    model.add(&Q2);
    model.add(&Q3);
    model.add(&Q4);
    model.add(&Q5);

    model.add(&f);
    model.add(&g);
    model.add(&r);
    model.add(&t);
    model.add(&u);
    model.add(&v);

    cout << endl;
    cout << "ANTES:" << endl;
    model.showModel();

    model.run(0, 100);

    cout << endl;
    cout << "DEPOIS:" << endl;
    model.showModel();

    assert(
        floatingPointComparison(Q1.getValue(),31.8513) == true
    );

    assert(
        floatingPointComparison(Q2.getValue(), 18.4003) == true
    );

    assert(
        floatingPointComparison(Q3.getValue(),77.1143) == true
    );

    assert(
        floatingPointComparison(Q4.getValue(),56.1728) == true
    );

    assert(
        floatingPointComparison(Q5.getValue(),16.4612) == true
    );


}