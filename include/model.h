#ifndef MODEL_H
#define MODEL_H

#include <string>

using namespace std;

class System;
class Flow;

class Model {
public:
    virtual ~Model() {}

    virtual string getId() const = 0;
    virtual void setId(const string& id) = 0;

    virtual bool run(int start, int finish) = 0;

    virtual void showModel() const = 0;

    virtual void add(System* system) = 0;
    virtual void add(Flow* flow) = 0;
};

#endif