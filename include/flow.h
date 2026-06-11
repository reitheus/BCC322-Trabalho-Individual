<<<<<<< HEAD
#ifndef FLOW_H
#define FLOW_H

#include <string>

using namespace std;

class System;

class Flow {
public:

    virtual ~Flow() = default;

    // Getters e setters
    virtual string getName() const = 0;
    virtual void setName(const string& name) = 0;

    virtual System* getSource() const = 0;
    virtual void setSource(System* source) = 0;

    virtual System* getTarget() const = 0;
    virtual void setTarget(System* target) = 0;


    // Método abstrato
    virtual double execute() = 0;
};

=======
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

>>>>>>> 9dbda6a123201c6dc76107ff8c4ed0c25a907394
#endif