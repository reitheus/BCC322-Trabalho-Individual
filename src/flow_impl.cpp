/**
 * @file flow_impl.cpp
 * @brief Implementação do Body (Flow_Impl) e do Handle (Flow).
 */

#include "../include/flow_impl.h"

using namespace std;

/// Classe Flow_Body

Flow_Body::Flow_Body() : name(""), source(nullptr), target(nullptr) {}

Flow_Body::Flow_Body(const string& name, System* source, System* target) : name(name), source(source), target(target) {}

Flow_Body::Flow_Body(const Flow_Body& other) : Body(),name(other.name), source(other.source), target(other.target) {}

Flow_Body::~Flow_Body() {}

Flow_Body& Flow_Body::operator=(const Flow_Body& other) {
    if (this == &other) return *this;

    name = other.name;
    source = other.source;
    target = other.target;

    return *this;
}

string Flow_Body::getName() const {
    return name;
}

void Flow_Body::setName(const string& name) {
    this->name = name;
}

System* Flow_Body::getSource() const {
    return source;
}

void Flow_Body::setSource(System* source) {
    this->source = source;
}

System* Flow_Body::getTarget() const {
    return target;
}

void Flow_Body::setTarget(System* target) {
    this->target = target;
}

double Flow_Body::execute() {
    return 0.0;
}

//=============================================================================================
///Classe Flow_Handle

Flow_Handle::Flow_Handle(Flow_Body* impl) : Handle<Flow_Body>(){
    this->pImpl_->detach();
    this->pImpl_ = impl;
    this->pImpl_->attach();
}

Flow_Handle::Flow_Handle(const Flow_Handle& other) : Handle<Flow_Body>(other) {}

Flow_Handle::~Flow_Handle() {}

Flow_Handle& Flow_Handle::operator=(const Flow_Handle& other) {
    Handle<Flow_Body>::operator=(other);
    return *this;
}

string Flow_Handle::getName() const { 
    return pImpl_->getName(); 
}

void Flow_Handle::setName(const string& n) {
    pImpl_->setName(n); 
}

System* Flow_Handle::getSource() const {
    return pImpl_->getSource(); 
}

void Flow_Handle::setSource(System* s) {
    pImpl_->setSource(s);
}

System* Flow_Handle::getTarget() const { 
    return pImpl_->getTarget(); 
}

void Flow_Handle::setTarget(System* t) {
    pImpl_->setTarget(t);
}

double Flow_Handle::execute() {
    return pImpl_->execute();
}