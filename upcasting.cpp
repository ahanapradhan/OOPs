#include <iostream>

using namespace std ;

class Shape {
public :
    Shape() = default;
    void draw() {
        cout << "Shape";
    }
};

class Circle : public Shape {
public :
    Circle() = default;
    void draw() {
        cout << "Circle";
    }
};

class Rectangle : public Shape {
public :
    Rectangle() = default;
    void draw() {
        cout << "Rectangle";
    }
};

int main() {
    Shape *p;
    Circle c;
    Rectangle r;
    p = &c; // Upcasting,
    p->draw(); //
    p = &r; // Upcasting
    p->draw();
}
