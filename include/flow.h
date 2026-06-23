class System;

class Flow {
public:
    virtual ~Flow() {}

    virtual string getName() const = 0;
    virtual void setName(const string& name) = 0;

    virtual System* getSource() const = 0;
    virtual void setSource(System* source) = 0;

    virtual System* getTarget() const = 0;
    virtual void setTarget(System* target) = 0;

    virtual double execute() = 0;
};