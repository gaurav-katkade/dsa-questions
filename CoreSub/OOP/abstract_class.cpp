#include<iostream>
using namespace std;
class Person{
    public:
    virtual void fun()=0;
};
class Student:public Person{
    public:
    void fun(){
        cout<<"fun of Student"<<endl;
    }
};
int main(){
    Person *p1;
    Student s1;
    p1 = &s1;
    // p1->fun();
    // s1.fun(); //OP fun of Student
}