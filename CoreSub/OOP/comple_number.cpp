#include <iostream>
using namespace std;
class Complex{
    public:
        int r;
        int i;
        Complex(){
            
        }
        Complex(int r,int i){
            this->r = r;
            this->i = i;
        }
        Complex add(Complex c){
            Complex temp;
            temp.r = r + c.r;
            temp.i = i+ c.i;
            return temp;
        }
        void getData(){
            cout<<r<<"+"<<i<<"i"<<endl;
        }
};
int main(){
    Complex c1(2,3);
    Complex c2(4,5);
    Complex c3;
    c3 = c1.add(c2);
    c3.getData();
    return 0;
}