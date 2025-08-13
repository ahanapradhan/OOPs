#include <iostream>
using namespace std;

class Cat {
protected:
    string name;
    char gender;
    string default_emotion;
    void get_emotional(const Cat&) const {
        cout << this->default_emotion << ":";
    }
public:
    Cat(const string name, const char gender) : name(name), gender(gender) {
        this->default_emotion = "jhcvoqjdbjkbd;qvjhvf";
    }
    string sayName() const { return name; }
    void sayHello(const Cat& visitor) const {
        this->get_emotional(visitor);
        cout << "Hello " << visitor.name << ":";
    }
};

class Qween : public Cat {
    void get_emotional(const Cat&) const {
        cout << "" << endl;
    }
public:
    Qween(const string name) : Cat(name, 'F') {
        this->default_emotion = "";
    }
    void sayHello(const Cat& visitor) const {
        this->get_emotional(visitor);
        cout << "Hello Whatever!"<< endl;
    }
};

class TomCat : public Cat {
    using Cat::get_emotional;
    string special_emotion;
    void get_emotional(const Qween&) const {
        cout << "wowwww...." << endl;
    }
public:
    TomCat(const string name) : Cat(name, 'M') {
        this->special_emotion = "Wowww...";
    }
    void sayHello(const Qween& visitor) const {
        this->get_emotional(visitor);
        cout << "Hello my Qweeeeenn " << visitor.sayName() << endl;
    }
    void sayHello(const Cat& visitor) const {
        this->get_emotional(visitor);
        cout << "Gurrr.. " << visitor.sayName() << endl;
    }
};




int main() {
    TomCat tom("Thomas Jasper Cat Sr."), blackRival("Casanova");
    Qween toodles("Toodles Galore");

    tom.sayHello(blackRival);   // no output, TomCat->Cat does nothing
    blackRival.sayHello(tom);
    tom.sayHello(toodles);
    toodles.sayHello(tom);// TomCat->Qween greets
    blackRival.sayHello(toodles);     // Qween says "Hello whatever!"
}
