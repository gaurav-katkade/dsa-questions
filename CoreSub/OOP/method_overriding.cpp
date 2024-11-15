#include<iostream>
using namespace std;
class A{
  public:
  void f1(){
      cout<<"f1 of parent class"<<endl;
  }
  void f2(){
      cout<<"f2 of parent class"<<endl;
  }
};
class B{
    public:
    void f1(){
        cout<<"f1 of child class"<<endl;
    }
    void f2(int x){
        cout<<"f2 of child class"<<endl;
    }
};
int main(){
    B b1;
    b1.f1();//f1 of child
    // b1.f2();//error
    b1.f2(5);//f2 of parent class
}