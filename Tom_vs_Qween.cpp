#include <string>
#include <iostream>
using namespace std;


class Qween {
    string name;
    string task;
    bool taskDone;
public:
    Qween(string name, string task) {
        this->name = name;
        this->task = task;
        this->taskDone = false;
    }
    void performTask(const string& name){
        cout << "Why do you think I want to work?? Go do "<< this->task << name<< " for me.." << endl;
        this->taskDone = true;
    }
};

class FlawlessCat {
    void assignTaskToQween(Qween& qween, const string& name) {
        qween.performTask(name);
    }

public:
    string name;

    int age;

    char gender;
    
    void sayHello(const FlawlessCat&  visitor, Qween& qween) {
        cout << "Hello " << visitor.name;
        this->assignTaskToQween(qween, this->name);
    }
};



int main() {
    Qween victoria("Victoria", "Rule");
    FlawlessCat tom = {"Thomas", 10, 'M'};
    FlawlessCat toodles = {"Toodles Galore", 2, 'F'};
    tom.sayHello(toodles, victoria);
}
