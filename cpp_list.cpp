#include <iostream>
#include <list>
using namespace std;

void print_list(list<int> ls) {
    for (auto num : ls)
        cout << num << " ";
    cout << endl;
}

int main() {
    list<int> ls;

    ls.push_back(12);   // 12
    ls.push_front(34);  // 34 12
    ls.push_back(19);   // 34 12 19
    ls.push_front(44);   // 44 34 12 19
    ls.push_back(31);    // 44 34 12 19 31
    ls.push_front(-8);   // -8 44 34 12 19 31

    print_list(ls);      // -8 44 34 12 19 31

    cout << ls.front() << endl; // -8
    cout << ls.back() << endl;  // 31

    ls.pop_back();   // delete 31
    ls.pop_back();   // delete 19
    ls.pop_front();  // delete -8
    ls.pop_front();  // delete 44

    print_list(ls);  // 34 12

    // insert elements
    list<int>::iterator litr;

    litr = ls.end();   // points beyond end
    litr--;            // points to 12
    ls.insert(litr, -20); // 34 -20 12

    litr--;            // points before -20
    ls.insert(litr, 33);  // 34 33 -20 12

    litr--;            // points before 33
    litr--;            // points before 34
    ls.insert(litr, 67);  // insert before 34

    print_list(ls);    // 67 34 33 -20 12

    // erase an element
    litr = ls.begin();
    ls.erase(litr);    // 67 deleted

    // reverse elements in the list
    ls.reverse();
    print_list(ls); // 12 -20 33 34

    ls.sort();
    cout << "Sorted list: " << endl;
    print_list(ls); // -20 12 33 34

    ls.sort(greater<int>());
    cout << "Reverse Sorted list: " << endl;
    print_list(ls); // 34 33 12 -20

    ls.clear(); // delete all
}

