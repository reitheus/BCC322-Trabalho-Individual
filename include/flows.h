#ifndef FLOWS_H
#define FLOWS_H

#include "flow.h"

class FlowExponencial : public Flow {
public:
    FlowExponencial();

    FlowExponencial(
        const string& name,
        System* source,
        System* target
    );

    FlowExponencial(
        const FlowExponencial& other
    );

    virtual ~FlowExponencial();

    FlowExponencial& operator=(
        const FlowExponencial& other
    );

    double execute() override;
};


class FlowLogistico : public Flow {
public:
    FlowLogistico();

    FlowLogistico(
        const string& name,
        System* source,
        System* target
    );

    FlowLogistico(
        const FlowLogistico& other
    );

    virtual ~FlowLogistico();

    FlowLogistico& operator=(
        const FlowLogistico& other
    );

    double execute() override;
};


class FlowComplexo : public Flow {
public:
    FlowComplexo();

    FlowComplexo(
        const string& name,
        System* source,
        System* target
    );

    FlowComplexo(
        const FlowComplexo& other
    );

    virtual ~FlowComplexo();

    FlowComplexo& operator=(
        const FlowComplexo& other
    );

    double execute() override;
};

#endif