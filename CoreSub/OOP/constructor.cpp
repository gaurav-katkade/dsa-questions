#include<algorithm>
#include<iostream>
using namespace std;
class Complex{
    // public:
    int a,b;
    public:
    Complex(){
        
    }
    Complex(int x,int y){
        a = x;b=y;
    }
    Complex(int x){
        a = x;
    }
    void getA(){
        cout<<a;
    }
};
int main(){
    // Complex c1 = 4;
    Complex c1=4;
    Complex c2 = c1;
    c2.getA();//op 4
    // cout<<c2.b;
    return 0;
}