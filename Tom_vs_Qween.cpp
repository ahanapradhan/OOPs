#include <string>
#include <iostream>
using namespace std;


class Qween {
    string name;
    string task;
    bool taskDone = false;
    void shout(const string& taskName) const {
        cout << "Why do you think I want to work?? Go "<< this->task << " to " << taskName<< " on my behalf.." << endl;
    }
public:
    void setDetails(string name, string task) {
        this->name = name;
        this->task = task;
        this->taskDone = false;
    }
    void pleaseOffer(const string& taskName){
        this->shout(taskName);
        cout << ":)"<<endl;
        this->taskDone = true;
    }
};

class FlawlessCat {
    string name;
    int age;
    char gender;

    void introduceToQween(Qween& qween, const string& name) {
        qween.pleaseOffer(name);
    }

public:
    void setDetails(const string& name, int age, char gender) {
        this->name = name;
        this->age = age;
        this->gender = gender;
    }
    void sayHello(const FlawlessCat&  visitor, Qween& qween) {
        cout << "Hello " << visitor.name << endl << "My name is " << this->name << endl;
        cout << "Let me introduce you to the Qween!" <<endl;
        this->introduceToQween(qween, visitor.name);
    }
};



int main() {
    Qween victoria;
    victoria.setDetails("Victoria", "offer tea");
    FlawlessCat tom;
    tom.setDetails("Thomas", 10, 'M');
    FlawlessCat toodles;
    toodles.setDetails("Toodles Galore", 2, 'F');
    tom.sayHello(toodles, victoria);
}
