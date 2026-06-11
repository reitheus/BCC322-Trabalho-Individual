#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H

#include <vector>
#include "model.h"
using namespace std;

// Forward declaration
class System;
class Flow;

class Model_Impl : public Model {
private:
    vector<System*> systems;
    vector<Flow*> flows;
    
public:

    // Forma canônica
    Model_Impl();
    
    virtual ~Model_Impl();

    // Métodos da UML
    void add(System* s);
    void add(Flow* f);

    bool run(int t_init, int t_final);

    void showModel() const;

private:
    Model_Impl(const Model_Impl& other);
    Model_Impl& operator=(const Model_Impl& other);

};

#endif