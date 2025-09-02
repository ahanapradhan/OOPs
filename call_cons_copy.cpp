#include <iostream>
using namespace std;
/* base class copy */

class Sample1 {
protected :
    int i;

public :
    Sample1(int j) {
        i = j;
        cout << "Base Constructor" << endl;
    } // constructor

    Sample1(const Sample1 &s) : i{s.i} {
        // copy constructor
        cout << "Copy base" << endl;
    }
};

class NewSample : public Sample1 {
private :
    int m;

public :
    NewSample(int k): Sample1(k) {
        //constructor
        m = 2 * i;
        cout << "Derived Constructor" << endl;
    }

    NewSample(const NewSample &n) : Sample1{n}, /* copy base */
                                    m{n.m} /* copy data member */
    {
        cout << "Copy Derived" << endl;
    }
};

int main() {
    NewSample ns1{2};
    NewSample ns2{ns1};

    NewSample ns3(3);
    NewSample ns4(ns3);
}
