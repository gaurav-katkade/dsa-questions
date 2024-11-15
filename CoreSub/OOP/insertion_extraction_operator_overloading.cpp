#include<iostream>
using namespace std;
class Complex{
    int x,y;
    public:
    void setData(int a,int b){
        x = a;y = b;
    }
    void getData(){
        cout<<x<<"+"<<y<<"i"<<endl;
    }
    friend ostream& operator<<(ostream&,Complex);
    friend istream& operator>>(istream&,Complex&);
};
ostream& operator<<(ostream& dout,Complex c){
    cout<<c.x<<"+"<<c.y<<"i"<<endl;
    return dout;
}
istream& operator>>(istream& din,Complex &c){
    cout<<"x ";
    cin>>c.x>>c.y;
    return din;
}
int main(){
    Complex c1;
    cin>>c1;
    cout<<c1;
    return 0;
}


//we can do same without friend function also
#include<iostream>
using namespace std;
class Complex{
    public:
    int x,y;
    void setData(int a,int b){
        x = a;y = b;
    }
    void getData(){
        cout<<x<<"+"<<y<<"i"<<endl;
    }
    // friend ostream& operator<<(ostream&,Complex);
    // friend istream& operator>>(istream&,Complex&);
};
ostream& operator<<(ostream& dout,Complex c){
    cout<<c.x<<"+"<<c.y<<"i"<<endl;
    return dout;
}
istream& operator>>(istream& din,Complex &c){
    cout<<"x ";
    cin>>c.x>>c.y;
    return din;
}
int main(){
    Complex c1;
    cin>>c1;
    cout<<c1;
    return 0;
}