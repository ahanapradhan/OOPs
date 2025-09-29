//multiple_exception.cpp
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

void demo_try_catch() {
    try {
        vector<int> check_array;
        for (int i = 0; i < 1; i++) {
            cout << check_array.at(i);
        }

    } 
    catch(const domain_error& e) {
        cout << "life is full of domain_errors" << endl;
        cout << e.what() << endl;
        cout << "domain_errors removed" << endl;
    }
    catch(const invalid_argument& e) {
        cout << "life is full of invalid_argument" << endl;
        cout << e.what() << endl;
        cout << "invalid_argument removed" << endl;
    }
    catch (const out_of_range& e) {
        cout << "life is full of thorns" << endl;
        cout << e.what() << endl;
        cout << "thorn removed" << endl;
    }
    cout << "\n--- demo_try_catch: life is bed of roses ---\n";
}
