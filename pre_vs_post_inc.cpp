#include <iostream>
using namespace std;

class Number {
    double value;

public:
    Number(double v = 0.0) : value(v) {}

    // Pre-increment: ++x
    Number& operator++() {
        ++value;          // increment first
        return *this;     // return updated object
    }

    // Post-increment: x++
    /* int parameter is not used in the code, so no need for a variable name
     compiler uses the different signatures to distinguish between the two operators */
    Number operator++(int) { 
        Number temp(*this);  // save old value
        value++;             // increment current
        return temp;         // return old copy
    }

    void print() const {
        cout << value << endl;
    }
};

int main() {
    Number n(5);

    cout << "Initial: ";
    n.print();

    cout << "Pre-increment (++n): ";
    (++n).print();   // increments, then prints

    cout << "Post-increment (n++): ";
    (n++).print();   // prints old, but n is incremented internally

    cout << "After post-increment: ";
    n.print();       // shows incremented value

    return 0;
}
