#include <iostream>
using namespace std;

class Point {
    int x, y;

public:
    // Constructor
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    // Operator overloading: add two points
    Point operator+(const Point &other) const {
        return Point(x + other.x, y + other.y);
    }

    // Operator overloading: subtract two points
    Point operator-(const Point &other) const {
        return Point(x - other.x, y - other.y);
    }

    // Operator overloading: compare two points
    bool operator==(const Point &other) const {
        return (x == other.x && y == other.y);
    }

    // Public getter for printing
    string toString() const {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }
};

int main() {
    Point p1(3, 4), p2(1, 2);

    // Using overloaded +
    Point sum = p1 + p2;
    cout << "p1 + p2 = " << sum.toString() << endl;

    // Using overloaded -
    Point diff = p1 - p2;
    cout << "p1 - p2 = " << diff.toString() << endl;

    // Using overloaded ==
    if (p1 == p2)
        cout << "p1 and p2 are equal" << endl;
    else
        cout << "p1 and p2 are not equal" << endl;

    return 0;
}
