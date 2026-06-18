/**
 * @file model_impl.cpp
 * @brief Implementação do Body (Model_Impl) e do Handle (Model).
 */

#include "../include/model_impl.h"

#include <iostream>
#include <vector>

using namespace std;

//Implementação Classe Model_Body

/**
 * @brief Inicialização do vetor estático de modelos.
 */
vector<Model_Body*> Model_Body::models;

Model_Body::Model_Body() : id_(""){}

Model_Body::Model_Body(const string& id) : id_(id){}

Model_Body::Model_Body(const Model_Body& other) : Body(), systems(other.systems), flows(other.flows), id_(other.id_){}

Model_Body::~Model_Body() {
    for (System_Body* s : systems) delete s;
    for (Flow_Body* f : flows) delete f;
    systems.clear();
    flows.clear();

    for (auto it = models.begin(); it != models.end(); ++it) {
        if (*it == this) {
            models.erase(it);
            break;
        }
    }
}

Model_Body& Model_Body::operator=(const Model_Body& other) {
    if (this == &other) return *this;
    systems = other.systems;
    flows = other.flows;
    id_ = other.id_;
    return *this;
}

void Model_Body::add(Flow_Body* f) {
    flows.push_back(f);
}

void Model_Body::add(Flow_Body* f, int i) {
    flows.insert(flows.begin() + (i - 1), f);
}

void Model_Body::add(System_Body* s) {
    systems.push_back(s);
}

System_Handle& Model_Body::createSystem(const string& id, double value) {
    System_Body* body = new System_Body(id, value);
    add(body);
    System_Handle* handle = new System_Handle(body);
    return *handle;
}

bool Model_Body::deleteFlow(Flow_Handle&) {
    return true;
}

bool Model_Body::deleteSystem(System_Handle&) {
    return true;
}

void Model_Body::setSource(Flow_Handle& f, System_Handle& s) {
    f.setSource(&s);
}

void Model_Body::setTarget(Flow_Handle& f, System_Handle& s) {
    f.setTarget(&s);
}

void Model_Body::clearSource(Flow_Handle& f) {
    f.setSource(nullptr);
}

void Model_Body::clearTarget(Flow_Handle& f) {
    f.setTarget(nullptr);
}

bool Model_Body::run(int t_init, int t_final) {

    for (int tempo = t_init; tempo < t_final; tempo++){
        vector<double> values;

        // executa todos os fluxos
        for (Flow_Body* flow : flows) {
            values.push_back(flow->execute());
        }

        // atualiza sistemas
        for (size_t i = 0; i < flows.size(); i++) {
            System_Handle* src = flows[i]->getSource();
            System_Handle* tgt = flows[i]->getTarget();
            if (src) src->setValue(src->getValue() - values[i]);
            if (tgt) tgt->setValue(tgt->getValue() + values[i]);
        }
    }

    return true;
}

void Model_Body::showModel() const {

    cout << "SYSTEMS" << endl;

    for (System_Body* s : systems) {

        cout << s->getName()
            << " = "
            << s->getValue()
            << endl;
    }

    cout << "FLOWS" << endl;

    for (Flow_Body* f : flows) {

        cout << f->getSource()->getName()
            << " -> "
            << f->getTarget()->getName()
            << endl;
    }
}

//=========================================================================
///Classe Model_Handle

Model_Handle::Model_Handle() : Handle<Model_Body>() {}

Model_Handle::Model_Handle(const string& id) : Handle<Model_Body>() {
    pImpl_->id_ = id;
}

Model_Handle::Model_Handle(const Model_Handle& other) : Handle<Model_Body>(other) {}
Model_Handle::~Model_Handle() {}

Model_Handle& Model_Handle::operator=(const Model_Handle& other) {
    Handle<Model_Body>::operator=(other);
    return *this;
}

System_Handle& Model_Handle::createSystem(const string& id, double value) {
    return pImpl_->createSystem(id, value);
}

bool Model_Handle::deleteFlow(Flow_Handle& f) {
    return pImpl_->deleteFlow(f);
}

bool Model_Handle::deleteSystem(System_Handle& s) { 
    return pImpl_->deleteSystem(s);
}

void Model_Handle::setSource(Flow_Handle& f, System_Handle& s) { 
    pImpl_->setSource(f, s);
}

void Model_Handle::setTarget(Flow_Handle& f, System_Handle& s) { 
    pImpl_->setTarget(f, s);
}

void Model_Handle::clearSource(Flow_Handle& f) { 
    pImpl_->clearSource(f);
}

void Model_Handle::clearTarget(Flow_Handle& f) { 
    pImpl_->clearTarget(f); 
}

bool Model_Handle::run(int t_init, int t_final) { 
    return pImpl_->run(t_init, t_final); 
}

void Model_Handle::showModel() const { 
    pImpl_->showModel();
}