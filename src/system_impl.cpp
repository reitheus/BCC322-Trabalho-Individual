/**
 * @file system_impl.cpp
 * @brief Implementação do Body (System_Impl) e do Handle (System).
 */

#include "../include/system_impl.h"

using namespace std;

//Implementação Body

System_Body::System_Body() : value(0.0), name("") {}

System_Body::System_Body(const string& name, double vaule) : value(vaule), name(name){}

System_Body::System_Body(const System_Body& other) : Body(),value(other.value), name(other.name){}

System_Body::~System_Body() {}

System_Body& System_Body::operator=(const System_Body& other) {
    if (this == &other) return *this;
    value = other.value;
    name = other.name;
    return *this;
}

string System_Body::getName() const {
    return name;
}

void System_Body::setName(const string& name_) {
    name = name_;
}

double System_Body::getValue() const {
    return value;
}

void System_Body::setValue(double value_) {
    value = value_;
}


//=================================================================================
//Implementação Handle


System_Handle::System_Handle() : Handle<System_Body>(){}

System_Handle::System_Handle(const string& name, double value) : Handle<System_Body>() {
    pImpl_->setName(name);
    pImpl_->setValue(value);
}

System_Handle::System_Handle(const System_Handle& other) : Handle<System_Body>(other){}

/**
 * @brief Construtor a partir de um Body pré-alocado.
 *
 * Handle<T>() cria um Body extra desnecessário — desanexamos e descartamos
 * esse Body vazio, depois apontamos pImpl_ para o Body fornecido.
 */
System_Handle::System_Handle(System_Body* impl) : Handle<System_Body>() {
    pImpl_->detach();
    pImpl_ = impl;
    pImpl_->attach();
}

System_Handle::~System_Handle() { pImpl_->detach(); }

System_Handle& System_Handle::operator=(const System_Handle& other) {
    Handle<System_Body>::operator=(other);
    return *this;
}


string System_Handle::getName() const {
    return pImpl_->getName();
}

void System_Handle::setName(const string& name) {
    pImpl_->setName(name);
}

double System_Handle::getValue() const {
    return pImpl_->getValue();
}

void System_Handle::setValue(double value) {
    pImpl_->setValue(value);
}