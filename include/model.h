#ifndef MODEL_H
#define MODEL_H

#include <string>

using namespace std;

class System;
class Flow;

class Model {
public:
    virtual ~Model() {}

    virtual bool run(int start, int finish) = 0;

    virtual void showModel() const = 0;

    virtual void add(System* system) = 0;
    virtual void add(Flow* flow) = 0;
    virtual bool deleteFlow(Flow& f) = 0;
    virtual bool deleteSystem(System& s) = 0;
    virtual void setSource(Flow& f, System& s) = 0;
    virtual void setTarget(Flow& f, System& s) =0;
    virtual void clearSource(Flow& f)=0;
    virtual void clearTarget(Flow& f)=0;
};

#endif