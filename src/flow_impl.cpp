#include "../include/flow_impl.h"
#include "../include/system_impl.h"

using namespace std;


// Construtor padrão
Flow_Impl::Flow_Impl()
    : name(""),
      source(nullptr),
      target(nullptr)
{}


// Construtor com parâmetros
Flow_Impl::Flow_Impl(const string& name,
           System* source,
           System* target)
    : name(name),
      source(source),
      target(target)
{}


// Construtor de cópia
Flow_Impl::Flow_Impl(const Flow_Impl& other)
    : name(other.name),
      source(other.source),
      target(other.target)
{}


// Destrutor
Flow_Impl::~Flow_Impl() {}


// Operador de atribuição
Flow_Impl& Flow_Impl::operator=(const Flow_Impl& other) {

    if(this == &other)
        return *this;

    name = other.name;
    source = other.source;
    target = other.target;

    return *this;
}


// Retorna nome
string Flow_Impl::getName() const {
    return name;
}


// Define nome
void Flow_Impl::setName(const string& name) {
    this->name = name;
}


// Retorna source
System* Flow_Impl::getSource() const {
    return source;
}


// Define source
void Flow_Impl::setSource(System* source) {
    this->source = source;
}


// Retorna target
System* Flow_Impl::getTarget() const {
    return target;
}


// Define target
void Flow_Impl::setTarget(System* target) {
    this->target = target;
}
