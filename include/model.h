#ifndef MODEL_H
#define MODEL_H

#include <vector>

using namespace std;

// Forward declaration
class System;
class Flow;

class Model {
public:

    virtual ~Model() = default;

    // Métodos da UML
    virtual void add(System* s) = 0;
    virtual void add(Flow* f) = 0;

    virtual bool run(int t_init, int t_final) = 0;

    virtual void showModel() const = 0;

};

#endif