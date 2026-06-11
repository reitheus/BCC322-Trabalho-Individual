#ifndef SYSTEM_IMPL_H
#define SYSTEM_IMPL_H

#include <string>
#include "system.h"

using namespace std;

class System_Impl : public System{
private:
    double value;
    string name;

public:
    // Forma canônica
    System_Impl();
    System_Impl(const string& name, double value);
    System_Impl(const System_Impl& other);
    virtual ~System_Impl();

    System_Impl& operator=(const System_Impl& other);

    // Métodos da UML
    string getName() const;
    void setName(const string& name);

    double getValue() const;
    void setValue(double value);
};

#endif