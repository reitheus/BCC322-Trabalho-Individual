#ifndef FLOW_IMPL_H
#define FLOW_IMPL_H

#include <string>
#include "flow.h"
#include "../include/system_impl.h"
using namespace std;

class System;

class Flow_Impl : public Flow {
protected:
    string name;
    System* source;
    System* target;

public:

    // Forma canônica
    Flow_Impl();
    Flow_Impl(const string& name,
              System* source,
              System* target);

    Flow_Impl(const Flow_Impl& other);

    virtual ~Flow_Impl();

    Flow_Impl& operator=(const Flow_Impl& other);

    // Getters e setters
    string getName() const;
    void setName(const string& name);

    System* getSource() const;
    void setSource(System* source);

    System* getTarget() const;
    void setTarget(System* target);


    // Método abstrato
    virtual double execute() = 0;

    };
#endif