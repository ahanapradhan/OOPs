#include <iostream>
using namespace std;

class Qween;


class Cat {
    string name;
    public:
    void setName(const string& name) {
        this->name = name;
    }
    void greet_joyfully(Cat other){
        cout << this->name <<": Hello " << other.getName() << endl;
    }
    string getName() const {
        return this->name;
    }
    void greet_joyfully(Qween other); // allowed for compilation, assuming that it is defined somewhere
    void talk_to(Qween other) {
        // error because this definition likely needs to use internals of Qween class,
        // which is not known at this moment
    }
};

class Qween {
    string name;
    public:
    void setName(const string& name) {
        this->name = name;
    }
    string getName() const {
        return this->name;
    }
    string talk() const {
        return "Bla bla bLa..";
    }
};
