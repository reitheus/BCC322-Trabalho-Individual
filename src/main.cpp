#include "../include/bib.hpp"
#include <iostream>

using namespace std;

int main() {
	int numero;
	cout << "Digite um número para calcular o fatorial: ";
	cin >> numero;
	int resultado = calcularFatorial(numero);
	if (resultado == -1) {
		cout << "Fatorial não definido para números negativos." << std::endl;
	} else {
		cout << "O fatorial de " << numero << " é: " << resultado << std::endl;
	}
	return 0;
}