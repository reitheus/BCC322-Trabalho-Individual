#ifndef FLOW_H
#define FLOW_H

#include <string>

using namespace std;

class System;

class Flow {
protected:
    string name;
    System* source;
    System* target;

public:

    // Forma canônica
    Flow();
    Flow(const string& name,
         System* source,
         System* target);

    Flow(const Flow& other);

    virtual ~Flow();

    Flow& operator=(const Flow& other);


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