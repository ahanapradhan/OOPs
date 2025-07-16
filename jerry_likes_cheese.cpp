#include <iostream>
#include <string>
using namespace std;

#define YUMMY "Yummy"

class Cheese {
    bool quality;
    bool isYuck(){
      return !(this->quality);
    }
public:
    void setData(string quality){
      this->quality = (quality == YUMMY);
    }
    bool isYummy(){
      return !(this->isYuck());
    }
};

class Mouse{
    string name;
    int age;
    bool ILikeIt(Cheese ch){
      return ch.isYummy();
    }
public:
    void setData(string name, int age){
      this->name = name;
      this->age = age;
    }
    string howDoYouLikeIt(Cheese ch){
      if (this->ILikeIt(ch)){
        return "yum yum!";
      }
      return "waaakkk!";
    }
};

int main(){
  Mouse jerry;
  Cheese yellow, limegreen;
  jerry.setData("jerry", 2);
  yellow.setData(YUMMY);
  limegreen.setData("Rubber");

  cout << jerry.howDoYouLikeIt(yellow) << endl;
  cout << jerry.howDoYouLikeIt(limegreen) << endl;
}
