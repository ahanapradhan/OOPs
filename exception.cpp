#include <iostream>
#include <string>
using namespace std;

class Object {
    std::string d_name;

public:
    Object(std::string str) : d_name(str) {}
    ~Object() {}

    void func() {
        Object stringToThrow("local");
        std::cout << "Calling func of " << d_name << std::endl;
        throw stringToThrow;
    }

    void hello() {
        std::cout << "Hello by " << d_name << std::endl;
    }
};
int main() {
    Object out("main object");

    try {
        out.func();
    }
    catch (Object o) {
        std::cout << "Caught exception" << std::endl;
        o.hello();
    }

    return 0;
}
