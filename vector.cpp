#include <vector>
#include <iostream>
using namespace std;

class Point {
    int x, y;

public:
    Point(int xx = 0, int yy = 0) {
        x = xx;
        y = yy;
    }

    friend ostream &operator<<(ostream &o, Point &p);
};

ostream &operator<<(ostream &o, Point &p) {
    o << "(" << p.x << ", " << p.y << ")" << endl;
    return o;
}

int main() {
    vector<Point> vp1;

    for (int i = 0; i < 5; i++)
        vp1.push_back(Point(i + 1, i + 1));

    for (auto pt : vp1)
        cout << pt; // (1, 1) (2, 2) (3, 3) (4, 4) (5, 5)

    cout << "Front: ";
    cout << vp1.front(); // (1, 1)

    cout << "Back: ";
    cout << vp1.back(); // (5, 5)

    vector<Point>::reverse_iterator ritr;
    for (ritr = vp1.rbegin(); ritr != vp1.rend(); ritr++)
        cout << *ritr; // (5, 5) (4, 4) (3, 3) (2, 2) (1, 1)

    cout << "Sizeof vp1: " << vp1.size() << endl; // 5

    vector<Point> vp2;
    vp2.assign(vp1.begin(), vp1.begin() + 3);

    for (auto pt : vp2)
        cout << pt; // (1, 1) (2, 2) (3, 3)
}
