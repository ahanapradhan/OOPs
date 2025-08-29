#include <iostream>
#include <string>
using namespace std;

/* globally overload the following operators to cout memory */
// you can use these overloads in your code for debugging
void* operator new(size_t size){
    void* mem = malloc(size);
    cout << "new got memory " << mem << endl;
    return mem;
}
void operator delete(void* mem) noexcept{
    cout << "delete for " << mem << endl;
    free(mem);
}
void operator delete(void* mem, size_t) noexcept{
  cout << "delete for " << mem << endl;
  free(mem);
}
/* End of -- globally overload the following operators to cout memory */



class HeapPoint{
  string* alias;
  public:

  HeapPoint(string& alias){
    this->alias = new string(alias);
  }
  ~HeapPoint(){
    showThis();
    cout << "HeapRef: before delete" << endl;
    delete this->alias;
    showThis();
    cout << "HeapRef: After delete" << endl;
  }
  void showThis(){
    cout << "[HeapPoint-" << this << "]";
  }
  void show(){
    showThis();
    cout << "[string-" << alias <<"]: " << *alias << endl;
  }

  // receiving and returning references to avoid copy, returning pointer is also fine
  HeapPoint& operator+ (const HeapPoint& other){
    showThis();
    cout <<" Adding" << endl;
    string temp = *alias;
    delete alias;
    alias = new string(temp + "-add-" + *(other.alias));
    return *(this);
  }
};


class StackPoint{
  string* alias; // all the methods should ensure Point has complete ownership on the memory
public:
  StackPoint(string& alias){
    this->alias = &alias;  // bad constructor design
    // caller's responsibility to make sure alias remains live as long as this Point is live
    // otherwise, Point alias will become a dangling pointer
  }
  ~StackPoint(){
    showThis();
    cout << "StackPoint: before delete" << endl;
   // delete this->alias;
   // since alias is a live string object outside, Point does not have ownership on the memory, so, should not delete
    showThis();
    cout << "StackPoint: After delete" << endl;
  }
  void showThis(){
    cout << "[StackPoint-" << this << "]";
  }
  void show(){
    showThis();
    cout << "[string-" << alias <<"]: " << *alias << endl;
  }

// receiving and returning references to avoid copy, returning pointer is also fine
  StackPoint& operator+ (const StackPoint& other){
    showThis();
    cout <<" Adding" << endl;
    string temp = *alias;
    // Point does not own the content of alias, so need to create new memory altogether for the new alias
    // this will create problem later, when `this' will be destroyed, alias will not be free -- memory leak
    alias = new string(temp + "-add-" + *(other.alias));
    return *this;
  }
};


void test_heap(){
   string str_p1 = "ahana_p1", str_p2 = "ahana_p2";
    HeapPoint p1(str_p1);
    HeapPoint p2(str_p2);
    p1.show();
    p2.show();
    p1 + p2;
    p1.show();
}

void test_stack(){
    string str_p1 = "ahana_p1", str_p2 = "ahana_p2";
    StackPoint p1(str_p1);
    StackPoint p2(str_p2);
    p1.show();
    p2.show();
    p1 + p2;
    p1.show();
}

int main()
{
    test_heap();

    test_stack();

    return 0;
}
