#include<iostream>
using namespace std;
class Complex{
    int a,b;
    public:
    void setData(int x,int y){
        a = x;b = y;
    }
    void getData(){
        cout<<a<<b<<endl;
    }
    friend void fun(Complex);
};
void fun(Complex c){
    cout<<c.a<<c.b;
    // cout<<"frind function called";
}
int main(){
    Complex c1;
    c1.setData(1,2);
    fun(c1);
    return 0;
}
