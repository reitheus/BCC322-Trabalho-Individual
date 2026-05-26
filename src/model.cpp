/**
 * @file model.cpp
 * @brief Implementação da classe Model.
 *
 * Este arquivo contém os métodos responsáveis
 * pela manipulação e execução dos modelos
 * de simulação do sistema dinâmico.
 */

#include "../include/model.h"
#include "../include/system.h"
#include "../include/flow.h"

#include <iostream>
#include <vector>

using namespace std;


// =====================
// Construtores
// =====================

/**
 * @brief Construtor padrão da classe Model.
 */
Model::Model() {}


/**
 * @brief Construtor de cópia da classe Model.
 *
 * @param other Outro objeto Model.
 */
Model::Model(const Model& other) {
    systems = other.systems;
    flows = other.flows;
}


// =====================
// Destrutor
// =====================

/**
 * @brief Destrutor da classe Model.
 *
 * Remove os elementos armazenados
 * nos vetores de sistemas e fluxos.
 */
Model::~Model() {
    systems.clear();
    flows.clear();
}


// =====================
// Operador de atribuição
// =====================

/**
 * @brief Operador de atribuição da classe Model.
 *
 * Copia os sistemas e fluxos de outro modelo.
 *
 * @param other Outro objeto Model.
 * @return Referência para o objeto atual.
 */
Model& Model::operator=(const Model& other) {

    if (this == &other)
        return *this;

    systems = other.systems;
    flows = other.flows;

    return *this;
}


// =====================
// Métodos de adição
// =====================

/**
 * @brief Adiciona um sistema ao modelo.
 *
 * @param s Ponteiro para o sistema.
 */
void Model::add(System* s) {
    systems.push_back(s);
}


/**
 * @brief Adiciona um fluxo ao modelo.
 *
 * @param f Ponteiro para o fluxo.
 */
void Model::add(Flow* f) {
    flows.push_back(f);
}


// =====================
// Simulação
// =====================

/**
 * @brief Executa a simulação do modelo.
 *
 * Percorre o intervalo de tempo especificado,
 * executando os fluxos e atualizando os valores
 * dos sistemas envolvidos.
 *
 * @param t_init Tempo inicial da simulação.
 * @param t_final Tempo final da simulação.
 *
 * @return true caso a execução ocorra corretamente.
 */
bool Model::run(int t_init, int t_final) {

    for (int tempo = t_init;
        tempo < t_final;
        tempo++)
    {
        vector<double> values;

        // executa todos os fluxos
        for (Flow* flow : flows) {
            values.push_back(flow->execute());
        }

        // atualiza sistemas
        for (unsigned int i = 0;
            i < flows.size();
            i++)
        {
            System* source = flows[i]->getSource();
            System* target = flows[i]->getTarget();

            if (source != nullptr) {
                source->setValue(
                    source->getValue() - values[i]
                );
            }

            if (target != nullptr) {
                target->setValue(
                    target->getValue() + values[i]
                );
            }
        }
    }

    return true;
}


// =====================
// Exibição
// =====================

/**
 * @brief Exibe os sistemas e fluxos do modelo.
 *
 * Mostra no terminal:
 * - sistemas cadastrados
 * - valores atuais
 * - conexões entre fluxos
 */
void Model::showModel() const {

    cout << "SYSTEMS" << endl;

    for (System* s : systems) {

        cout << s->getName()
            << " = "
            << s->getValue()
            << endl;
    }

    cout << endl;
    cout << "FLOWS" << endl;

    for (Flow* f : flows) {

        cout << f->getSource()->getName()
            << " -> "
            << f->getTarget()->getName()
            << endl;
    }
}