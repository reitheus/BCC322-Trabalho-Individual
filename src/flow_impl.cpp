/**
 * @file flow_impl.cpp
 * @brief Implementação do Body (Flow_Impl) e do Handle (Flow).
 */

#include "../include/flow_impl.h"

using namespace std;

/// Classe Flow_Body

Flow_Body::Flow_Body() : name(""), source(nullptr), target(nullptr) {}

Flow_Body::Flow_Body(const string& name, System_Handle* source, System_Handle* target) : name(name), source(source), target(target) {}

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

System_Handle* Flow_Body::getSource() const {
    return source;
}

void Flow_Body::setSource(System_Handle* source) {
    this->source = source;
}

System_Handle* Flow_Body::getTarget() const {
    return target;
}

void Flow_Body::setTarget(System_Handle* target) {
    this->target = target;
}

//=============================================================================================
///Classe Flow_Handle

Flow_Handle::Flow_Handle(Flow_Body* impl) : pImpl_(impl) {
    pImpl_->attach();
}

Flow_Handle::Flow_Handle(const Flow_Handle& other) : pImpl_(other.pImpl_) {
    pImpl_->attach();
}

Flow_Handle::~Flow_Handle() {
    pImpl_->detach();
}

Flow_Handle& Flow_Handle::operator=(const Flow_Handle& other) {
    if (this != &other) {
        other.pImpl_->attach();
        pImpl_->detach();
        pImpl_ = other.pImpl_;
    }
    return *this;
}

string Flow_Handle::getName() const { 
    return pImpl_->getName(); 
}

void Flow_Handle::setName(const string& n) {
    pImpl_->setName(n); 
}

System_Handle* Flow_Handle::getSource() const {
    return pImpl_->getSource(); 
}

void Flow_Handle::setSource(System_Handle* s) {
    pImpl_->setSource(s);
}

System_Handle* Flow_Handle::getTarget() const { 
    return pImpl_->getTarget(); 
}

void Flow_Handle::setTarget(System_Handle* t) {
    pImpl_->setTarget(t);
}

double Flow_Handle::execute() {
    return pImpl_->execute(); 
}