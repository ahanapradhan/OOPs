// exception_unwinding_demo.cpp
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

struct TraceObj {
    string name;
    TraceObj(const string& n) : name(n) {
        cout << "Constructing " << name << endl;
    }
    ~TraceObj() {
        cout << "Destructing  " << name << endl;
    }
};

void dummy_code() {
    for (int i=0; i< 10; i++) cout << i << " normal execution reached" << endl;
}

void problematic_func() {
    TraceObj inner("Inner");
    cout << "About to throw from inner" << endl;
    throw runtime_error("error-from-inner");
}

void demo_catch_at_outer() {
    cout << endl<<"--- demo_catch_at_outer: throw in inner, catch in outer ---" << endl;
    try {
        TraceObj outer("Outer");
        {   // middle block
            TraceObj middle("Middle");
            {   // inner block
                problematic_func();
            }
            cout << "Continuing after middle object creation" << endl;
        }
        cout << "Continuing after outer object creation" << endl;
    }
    catch (const exception& e) {
        cout << "Caught in outer: " << e.what() << endl;
    }
    dummy_code();
}

void demo_catch_at_middle() {
    cout << endl << "--- demo_catch_at_middle: throw in inner, catch in middle ---" << endl;
    TraceObj outer("Outer");          // constructed outside try so survives a middle catch
    try {
        TraceObj middle("Middle");
        try {
            problematic_func();
        }
        catch (const exception& e) {
            cout << "Caught in middle: " << e.what() << endl;
        }
        cout << "Continuing after middle object creation" << endl;
    }
    catch (...) {
        cout << "This outer catch will not run in this demo" << endl;
    }
    dummy_code();
}

int main() {
    //demo_catch_at_outer();
    demo_catch_at_middle();

    cout << "\n--- program end ---\n";
    return 0;
}
