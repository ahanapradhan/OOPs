#include <iostream>
using namespace std;
class ComplexNumber {
    double r, i;

public:
    ComplexNumber(const double r=0.0, const double i=0.0) {
        this->r = r;
        this->i = i;
    }

    ComplexNumber operator+(const ComplexNumber x) {
        ComplexNumber t;              // uses default constructor (r=0, i=0)
        t.r = r + x.r;
        t.i = i + x.i;
        return t;
    }

    void display() {
        cout << r << " + " << i << "i" << endl;
    }
};

int main() {
    ComplexNumber a(1.5, 2.5);   // creates a complex number (1.5 + 2.5i)
    double d = 1.5;     // a plain double

    ComplexNumber x, y;

    x = a + d;  // x = a.operator+( Comp(d) );
    x.display();
   // y = d + a;  // d.operator+(Comp(a)) --> + is not defined for double. So, not ok


    return 0;
}
