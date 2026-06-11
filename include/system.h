<<<<<<< HEAD
#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

class System {
public:
   
    virtual ~System() = default;

    // Métodos da UML
    virtual string getName() const = 0;
    virtual void setName(const string& name) = 0;

    virtual double getValue() const = 0;
    virtual void setValue(double value) = 0;
};

=======
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

>>>>>>> 9dbda6a123201c6dc76107ff8c4ed0c25a907394
#endif