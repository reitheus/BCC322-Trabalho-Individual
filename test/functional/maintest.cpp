#include "../include/bib.hpp"
#include <iostream>
#include <assert.h>

using namespace std;

void testefat() {
    assert(calcularFatorial(0) == 1);
	assert(calcularFatorial(1) == 1);
	assert(calcularFatorial(5) == 120);
	assert(calcularFatorial(-1) == -1);
    cout << "Todos os testes passaram!" << endl;
 }

int main() {
    testefat();
    return 0;
}