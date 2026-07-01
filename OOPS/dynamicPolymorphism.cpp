// use of virtual function to implement dynamic runtime Polymorphism
#include<iostream>
using namespace std;
class animal{
public:
virtual void speak(){
  cout<<"Animal\n";
}
};

class dog:public animal{
void speak() override {
  cout<<"Dog\n";
}
};
int main(){
  animal *a = new dog();
  a->speak();
  return 0;
}
