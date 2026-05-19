#ifndef MODEL_H
#define MODEL_H

#include <vector>

using namespace std;

// Forward declaration
class System;
class Flow;

class Model {
private:
    vector<System*> systems;
    vector<Flow*> flows;

public:

    // Forma canônica
    Model();
    Model(const Model& other);
    virtual ~Model();

    Model& operator=(const Model& other);

    // Métodos da UML
    void add(System* s);
    void add(Flow* f);

    bool run(int t_init, int t_final);

    void showModel() const;
};

#endif