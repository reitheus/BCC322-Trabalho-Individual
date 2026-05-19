#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

class System {
private:
    double value;
    string name;

public:
    // Forma canônica
    System();
    System(const string& name, double value);
    System(const System& other);
    virtual ~System();

    System& operator=(const System& other);

    // Métodos da UML
    string getName() const;
    void setName(const string& name);

    double getValue() const;
    void setValue(double value);
};

#endif