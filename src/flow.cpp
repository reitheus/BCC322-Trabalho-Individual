#include "../include/Flow.h"
#include "../include/System.h"

using namespace std;


// Construtor padrão
Flow::Flow()
    : name(""),
      source(nullptr),
      target(nullptr)
{}


// Construtor com parâmetros
Flow::Flow(const string& name,
           System* source,
           System* target)
    : name(name),
      source(source),
      target(target)
{}


// Construtor de cópia
Flow::Flow(const Flow& other)
    : name(other.name),
      source(other.source),
      target(other.target)
{}


// Destrutor
Flow::~Flow() {}


// Operador de atribuição
Flow& Flow::operator=(const Flow& other) {

    if(this == &other)
        return *this;

    name = other.name;
    source = other.source;
    target = other.target;

    return *this;
}


// Retorna nome
string Flow::getName() const {
    return name;
}


// Define nome
void Flow::setName(const string& name) {
    this->name = name;
}


// Retorna source
System* Flow::getSource() const {
    return source;
}


// Define source
void Flow::setSource(System* source) {
    this->source = source;
}


// Retorna target
System* Flow::getTarget() const {
    return target;
}


// Define target
void Flow::setTarget(System* target) {
    this->target = target;
}
