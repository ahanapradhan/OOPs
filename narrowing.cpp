#include <iostream>
using namespace std;

class A {
public:
    int value;
    A(int v) {
        this->value = v;
    }
};
class B {
public:
    short value;
    B(int v) {
        this->value = v;
    }  // potential narrowing
};

int main() {
    A a1{42};      // fine: int fits in int
    B b1{42};      // fine: int fits in short
    cout << a1.value << endl << b1.value << endl;

    // Narrowing examples:
    B b2{70000};   // ERROR: 70000 doesn't fit in short
    cout << "b2.value = " << b2.value << endl;

    A a2{70000};   // fine: int → int
    B b3{static_cast<int>(a2.value)}; // explicit conversion OK

    cout << "a2.value = " << a2.value << endl;
    cout << "b3.value = " << b3.value << endl;
}
