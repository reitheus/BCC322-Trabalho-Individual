#include "../include/model_impl.h"
#include "../include/system.h"
#include "../include/flow.h"

#include <iostream>
#include <vector>

using namespace std;


/// Construtor padrão
Model_Impl::Model_Impl() {}


/// Construtor de cópia
Model_Impl::Model_Impl(const Model_Impl& other) {
    systems = other.systems;
    flows = other.flows;
}


/// Destrutor
Model_Impl::~Model_Impl() {
    systems.clear();
    flows.clear();
}


/// Operador de atribuição
Model_Impl& Model_Impl::operator=(const Model_Impl& other) {

    if(this == &other)
        return *this;

    systems = other.systems;
    flows = other.flows;

    return *this;
}


/// Adiciona sistema
void Model_Impl::add(System* s) {
    systems.push_back(s);
}


/// Adiciona fluxo
void Model_Impl::add(Flow* f) {
    flows.push_back(f);
}


/// Executa simulação
bool Model_Impl::run(int t_init, int t_final) {

    for(int tempo = t_init;
        tempo < t_final;
        tempo++)
    {
        vector<double> values;

        // executa todos os fluxos
        for(Flow* flow : flows) {
            values.push_back(flow->execute());
        }

        // atualiza sistemas
        for(unsigned int i = 0;
            i < flows.size();
            i++)
        {
            System* source = flows[i]->getSource();
            System* target = flows[i]->getTarget();

            if(source != nullptr) {
                source->setValue(
                    source->getValue() - values[i]
                );
            }

            if(target != nullptr) {
                target->setValue(
                    target->getValue() + values[i]
                );
            }
        }
    }

    return true;
}


/// Mostra modelo
void Model_Impl::showModel() const {

    cout << "SYSTEMS" << endl;

    for(System* s : systems) {

        cout << s->getName()
             << " = "
             << s->getValue()
             << endl;
    }

    cout << endl;
    cout << "FLOWS" << endl;

    for(Flow* f : flows) {

        cout << f->getSource()->getName()
             << " -> "
             << f->getTarget()->getName()
             << endl;
    }
}
