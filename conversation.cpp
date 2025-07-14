#include <iostream>
using namespace std;

class Cat {
protected:
    string name;
    char gender;
public:
    Cat(string name, char gender) {
        this->name = name;
        this->gender = gender;
    }

    string sayName() {
        return this->name;
    }

    void sayHello(Cat* visitor) {
        cout << "Hello" << visitor->sayName() << "!" << endl;
        cout << "I am " << this->sayName() << ". How are you doing Today?" << endl;
    }
};

class Qween: public Cat {
public:
    Qween(string name): Cat(name, 'F') {
    }

    void sayHello(Cat* visitor) {
        cout << "Hello whatever!" << endl;
    }
};

class TomCat: public Cat {
public:
    TomCat(string name): Cat(name, 'M') {
    }

    void sayHello(Qween* visitor) {
        cout << "Hello my qween "<< visitor->sayName() <<"!" << endl;
    }
};

int main() {
    TomCat tom("Thomas Jasper Cat Sr."), blackRival("Casanova");
    Qween toodles("Toodles Galore");

    Cat* tom_p = &tom;
    Cat* black_p = &blackRival;
    Qween* toodles_p = &toodles;

    tom_p->sayHello(black_p);
    tom_p->sayHello(toodles_p);
    tom.sayHello(toodles_p);

    toodles_p->sayHello(tom_p);
}


