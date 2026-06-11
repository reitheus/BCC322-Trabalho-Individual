<<<<<<< HEAD
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

=======
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

>>>>>>> 9dbda6a123201c6dc76107ff8c4ed0c25a907394
#endif