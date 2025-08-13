#include <iostream>
using namespace std;

void explain_const() {
    int const one = 1;
    const int one_plus = 1;
    //one++;
    //one_plus++;
    cout << one + one_plus << endl;

    int two = 2;
    int five = 5;
    int * const some_ptr = &two; // constant pointer
    int const * other_ptr = &two; // pointer to constant
    cout << *some_ptr << " " << *other_ptr << endl;
    //some_ptr = &five;
    //some_ptr++;
    (*some_ptr)++;
    other_ptr = &five;
    cout << *some_ptr << " " << *other_ptr << endl;
    //(*other_ptr)++;
    other_ptr++;
    cout << *some_ptr << " " << other_ptr << endl;

    const int * another_ptr = &two; // pointer to constant -- value of two is 3 here
    cout << *some_ptr << " " << *another_ptr << endl;
    another_ptr = &five;
    cout << *some_ptr << " " << *another_ptr << endl;
    //(*another_ptr)++;
    another_ptr++;
    cout << *some_ptr << " " << another_ptr << endl;
}

int main() {
    explain_const();
}
