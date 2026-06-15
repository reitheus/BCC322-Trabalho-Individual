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

#include "model_impl.h"
#include "../include/model.h"
#include "../include/system.h"
#include "../include/flow.h"

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Inicialização do vetor estático de modelos.
 */
vector<Model*> Model_Impl::models;

/**
 * @brief Construtor parametrizado da classe Model_Impl.
 *
 * Inicializa o modelo com o identificador fornecido e
 * vetores de sistemas e fluxos vazios.
 *
 * @param id Identificador único do modelo.
 */
Model_Impl::Model_Impl(string id) : id_(id) {}

/**
 * @brief Delega a criação de um modelo para Model_Impl::createModel.
 *
 * Ponto de entrada estático da interface Model que redireciona
 * a chamada para a implementação concreta em Model_Impl.
 *
 * @param id Identificador único do modelo.
 * @return Referência para o modelo recém-criado.
 */
Model& Model::createModel(string id) {
    return Model_Impl::createModel(id);
}

/**
 * @brief Cria e registra uma nova instância de Model_Impl.
 *
 * Instancia um Model_Impl com o identificador fornecido,
 * registra-o no vetor estático de modelos e retorna a referência.
 *
 * @param id Identificador único do modelo.
 * @return Referência para o modelo recém-criado.
 */
Model& Model_Impl::createModel(string id) {
    Model* model = new Model_Impl(id);
    models.push_back(model);
    return *model;
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
Model_Impl::~Model_Impl(void) {

    for (vector<System*>::iterator it = systems.begin(); it != systems.end(); ++it) {
        delete (System_Impl*)*it;
    }
    for (vector<Flow*>::iterator it = flows.begin(); it != flows.end(); ++it) {
        delete (Flow_Impl*)*it;
    }

    systems.clear();
    flows.clear();

    // Remove este model do vetor estático
    for (auto it = models.begin(); it != models.end(); ++it) {
        if (*it == this) {
            models.erase(it);
            break;
        }
    }

}



/**
 * @brief Registra um modelo no vetor estático interno.
 *
 * @param m Ponteiro para o modelo a ser registrado.
 */
void Model_Impl::add(Model* m) {
    models.push_back(m);
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
 * @brief Cria e adiciona um sistema ao modelo.
 *
 * Instancia um System_Impl com o identificador e valor inicial fornecidos,
 * adiciona-o ao vetor interno de sistemas e retorna a referência.
 *
 * @param id Identificador do sistema.
 * @param value Valor inicial do sistema.
 * @return Referência para o sistema recém-criado.
 */
System& Model_Impl::createSystem(string id, double value) {
    System* system = new System_Impl(id, value);
    add(system);
    return *system;
}

/**
 * @brief Remove um fluxo do modelo.
 *
 * Implementação atual retorna sempre true (stub).
 *
 * @param f Referência para o fluxo a ser removido.
 * @return true indicando sucesso.
 */
bool Model_Impl::deleteFlow(Flow&) {
    return true;
}

/**
 * @brief Remove um sistema do modelo.
 *
 * Implementação atual retorna sempre true (stub).
 *
 * @param s Referência para o sistema a ser removido.
 * @return true indicando sucesso.
 */
bool Model_Impl::deleteSystem(System&) {
    return true;
}

/**
 * @brief Define o sistema de origem de um fluxo.
 *
 * Realiza cast do fluxo para Flow_Impl e invoca setSource().
 *
 * @param f Referência para o fluxo a ser configurado.
 * @param s Referência para o sistema que será a origem.
 */
void Model_Impl::setSource(Flow& f, System& s) {
    Flow_Impl* fi = (Flow_Impl*)&f;
    fi->setSource(&s);
}

/**
 * @brief Define o sistema de destino de um fluxo.
 *
 * Realiza cast do fluxo para Flow_Impl e invoca setTarget().
 *
 * @param f Referência para o fluxo a ser configurado.
 * @param s Referência para o sistema que será o destino.
 */
void Model_Impl::setTarget(Flow& f, System& s) {
    Flow_Impl* fi = (Flow_Impl*)&f;
    fi->setTarget(&s);
}

/**
 * @brief Insere um fluxo em posição específica do vetor de fluxos.
 *
 * @param f Ponteiro para o fluxo a ser inserido.
 * @param i Posição de inserção (1-indexada).
 */
void Model_Impl::add(Flow* f, int i) {
    flows.insert(flows.begin() + (i - 1), f);
}

/**
 * @brief Remove o sistema de origem de um fluxo, definindo-o como nulo.
 *
 * @param f Referência para o fluxo cujo source será limpo.
 */
void Model_Impl::clearSource(Flow& f) {
    Flow_Impl* fi = (Flow_Impl*)&f;
    fi->setSource(nullptr);
}

/**
 * @brief Remove o sistema de destino de um fluxo, definindo-o como nulo.
 *
 * @param f Referência para o fluxo cujo target será limpo.
 */
void Model_Impl::clearTarget(Flow& f) {
    Flow_Impl* fi = (Flow_Impl*)&f;
    fi->setTarget(nullptr);
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