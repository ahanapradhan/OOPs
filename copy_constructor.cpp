#include <iostream>
#include <string>
using namespace std;

class Cheese {
private:
    string type;
    int age; // in days
public:
    // Constructor
    Cheese(string t, int a) : type(t), age(a) {}

    // Copy Constructor
    Cheese(const Cheese &c) {
        type = c.type;
        age = c.age;
        cout << "Copy constructor called! Cloning " << type << endl;
    }

    // Display
    void show() const {
        cout << "Cheese: " << type << ", Age: " << age << " days" << endl;
    }
};

int main() {
    Cheese brie("Brie", 10); // original cheese
    brie.show();

    // Create clone using copy constructor
    Cheese brieClone = brie;
    brieClone.show();

    // Another clone
    Cheese anotherClone(brie);
    anotherClone.show();

    return 0;
}
