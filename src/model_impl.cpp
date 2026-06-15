/**
 * @file model_impl.cpp
 * @brief Implementação da classe Model_Impl.
 *
 * Este arquivo contém os métodos responsáveis pela manipulação
 * e execução dos modelos de simulação de sistemas dinâmicos,
 * incluindo construtores, destrutor, operador de atribuição,
 * adição de sistemas e fluxos, execução da simulação e exibição
 * do estado do modelo.
 */

#include "../include/model_impl.h"
#include "../include/system.h"
#include "../include/flow.h"

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Construtor padrão da classe Model_Impl.
 *
 * Inicializa o modelo com vetores de sistemas e fluxos vazios.
 */
Model_Impl::Model_Impl() {}

/**
 * @brief Construtor de cópia da classe Model_Impl.
 *
 * Copia os vetores de sistemas e fluxos de outro modelo.
 *
 * @param other Objeto Model_Impl a ser copiado.
 */
Model_Impl::Model_Impl(const Model_Impl& other) {
    systems = other.systems;
    flows = other.flows;
}

/**
 * @brief Destrutor da classe Model_Impl.
 *
 * Limpa os vetores de sistemas e fluxos.
 * Os objetos apontados pelos ponteiros não são destruídos
 * (responsabilidade do código cliente).
 */
Model_Impl::~Model_Impl() {
    systems.clear();
    flows.clear();
}

/**
 * @brief Operador de atribuição da classe Model_Impl.
 *
 * Copia os vetores de sistemas e fluxos de outro modelo.
 *
 * @param other Objeto Model_Impl a ser atribuído.
 * @return Referência para o objeto atual.
 */
Model_Impl& Model_Impl::operator=(const Model_Impl& other) {
    if (this == &other)
        return *this;

    systems = other.systems;
    flows = other.flows;

    return *this;
}

/**
 * @brief Adiciona um sistema ao modelo.
 *
 * @param s Ponteiro para o sistema a ser adicionado.
 */
void Model_Impl::add(System* s) {
    systems.push_back(s);
}

/**
 * @brief Adiciona um fluxo ao modelo.
 *
 * @param f Ponteiro para o fluxo a ser adicionado.
 */
void Model_Impl::add(Flow* f) {
    flows.push_back(f);
}

/**
 * @brief Executa a simulação do modelo no intervalo de tempo especificado.
 *
 * A cada passo de tempo, todos os fluxos são calculados com base nos
 * valores atuais dos sistemas (passo síncrono), e em seguida os sistemas
 * de origem e destino de cada fluxo são atualizados simultaneamente.
 *
 * @param t_init Tempo inicial da simulação (inclusive).
 * @param t_final Tempo final da simulação (exclusive).
 * @return true se a execução foi concluída com sucesso.
 */
bool Model_Impl::run(int t_init, int t_final) {
    for (int tempo = t_init; tempo < t_final; tempo++) {

        vector<double> values;

        // Calcula todos os fluxos com base nos valores atuais
        for (Flow* flow : flows) {
            values.push_back(flow->execute());
        }

        // Atualiza os sistemas com os valores calculados
        for (unsigned int i = 0; i < flows.size(); i++) {
            System* source = flows[i]->getSource();
            System* target = flows[i]->getTarget();

            if (source != nullptr)
                source->setValue(source->getValue() - values[i]);

            if (target != nullptr)
                target->setValue(target->getValue() + values[i]);
        }
    }

    return true;
}

/**
 * @brief Exibe no console os sistemas e fluxos do modelo.
 *
 * Para cada sistema, imprime seu nome e valor atual.
 * Para cada fluxo, imprime a conexão entre sistema de origem
 * e sistema de destino no formato "origem -> destino".
 */
void Model_Impl::showModel() const {
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