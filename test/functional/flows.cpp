<<<<<<< HEAD
#include "../../include/flows.h"
#include "../../include/system.h"

//Flow exponencial
FlowExponencial::FlowExponencial() : Flow_Impl() {}

FlowExponencial::FlowExponencial(const string& name, System* source, System* target)
    : Flow_Impl(name, source, target) {}

FlowExponencial::FlowExponencial(const FlowExponencial& other)
    : Flow_Impl(other) {}

FlowExponencial::~FlowExponencial() {}

FlowExponencial& FlowExponencial::operator=(const FlowExponencial& other) {
    if (this == &other) {
        return *this;
    }

    Flow_Impl::operator=(other);
    return *this;
}

double FlowExponencial::execute() {
    return 0.01 * getSource()->getValue();
}

//Flow LOgistico
FlowLogistico::FlowLogistico() : Flow_Impl() {}

FlowLogistico::FlowLogistico(const string& name, System* source, System* target)
    : Flow_Impl(name, source, target) {}

FlowLogistico::FlowLogistico(const FlowLogistico& other)
    : Flow_Impl(other) {}

FlowLogistico::~FlowLogistico() {}

FlowLogistico& FlowLogistico::operator=(const FlowLogistico& other) {
    if (this == &other) {
        return *this;
    }

    Flow_Impl::operator=(other);
    return *this;
}

double FlowLogistico::execute() {
    double p = getTarget()->getValue();

    return 0.01 * p * (1 - p / 70.0);
}

// =====================
// FlowComplexo
// =====================

FlowComplexo::FlowComplexo() : Flow_Impl() {}

FlowComplexo::FlowComplexo(const string& name, System* source, System* target)
    : Flow_Impl(name, source, target) {}

FlowComplexo::FlowComplexo(const FlowComplexo& other)
    : Flow_Impl(other) {}

FlowComplexo::~FlowComplexo() {}

FlowComplexo& FlowComplexo::operator=(const FlowComplexo& other) {
    if (this == &other) {
        return *this;
    }

    Flow_Impl::operator=(other);
    return *this;
}

double FlowComplexo::execute() {
    return 0.01 * getSource()->getValue();
=======
#include "../../include/flows.h"
#include "../../include/system.h"

//Flow exponencial
FlowExponencial::FlowExponencial() : Flow() {}

FlowExponencial::FlowExponencial(const string& name, System* source, System* target)
    : Flow(name, source, target) {}

FlowExponencial::FlowExponencial(const FlowExponencial& other)
    : Flow(other) {}

FlowExponencial::~FlowExponencial() {}

FlowExponencial& FlowExponencial::operator=(const FlowExponencial& other) {
    if (this == &other) {
        return *this;
    }

    Flow::operator=(other);
    return *this;
}

double FlowExponencial::execute() {
    return 0.01 * getSource()->getValue();
}

//Flow LOgistico
FlowLogistico::FlowLogistico() : Flow() {}

FlowLogistico::FlowLogistico(const string& name, System* source, System* target)
    : Flow(name, source, target) {}

FlowLogistico::FlowLogistico(const FlowLogistico& other)
    : Flow(other) {}

FlowLogistico::~FlowLogistico() {}

FlowLogistico& FlowLogistico::operator=(const FlowLogistico& other) {
    if (this == &other) {
        return *this;
    }

    Flow::operator=(other);
    return *this;
}

double FlowLogistico::execute() {
    double p = getTarget()->getValue();

    return 0.01 * p * (1 - p / 70.0);
}

// =====================
// FlowComplexo
// =====================

FlowComplexo::FlowComplexo() : Flow() {}

FlowComplexo::FlowComplexo(const string& name, System* source, System* target)
    : Flow(name, source, target) {}

FlowComplexo::FlowComplexo(const FlowComplexo& other)
    : Flow(other) {}

FlowComplexo::~FlowComplexo() {}

FlowComplexo& FlowComplexo::operator=(const FlowComplexo& other) {
    if (this == &other) {
        return *this;
    }

    Flow::operator=(other);
    return *this;
}

double FlowComplexo::execute() {
    return 0.01 * getSource()->getValue();
>>>>>>> 9dbda6a123201c6dc76107ff8c4ed0c25a907394
}