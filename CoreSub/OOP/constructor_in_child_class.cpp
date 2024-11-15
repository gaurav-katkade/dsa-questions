#include<iostream>
using namespace std;
class A{
  int a;
  public:
    A(){
        cout<<"parent";
    }
};
class B:public A{
  int b;
  public:
  B():A(){
      cout<<"child";
  }
};
int main(){
    B b1;
    return 0;
}

#include<iostream>
using namespace std;
class A{
  int a;
  public:
    A(int k){
        a = k;
    }
};
class B:public A{
  int b;
  public:
  B(int x,int y):A(x){
      b=y;
  }
};
int main(){
    B b1(2,3);
    return 0;
}