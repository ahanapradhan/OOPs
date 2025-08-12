#include <iostream>
using namespace std;

class Engine {
    string model_name;
public:
    Engine(){
       this->model_name = "PistonicBoom";
       cout<< "Your neighbors will hate you." <<endl;
    }
    Engine(string model_name){
        this->model_name = model_name;
        cout << "Engine " << this->model_name << " constructed "<<endl;
    }
    ~Engine() {
        cout << "Engine " << this->model_name << " destructed "<<endl;
    }
};

class Car {
    Engine e;
    string model_name;
public:
    Car() {
        this->model_name = "SnailMobile Turbo";
        cout << "I hope someday you will reach your destination!"<< endl;
    }
    ~Car() {
        cout << "Car destroyed" << endl;
    }
};

void createCar() {
    Car c;
    cout << "I hope you had a good time travelling! now go and do your assignment!"<<endl;
}

int main() {
    cout << "Hello there..." << endl;
    createCar();
    cout << "Byeeee" <<endl;
    return 0;
}
