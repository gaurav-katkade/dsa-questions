#include <iostream>
using namespace std;
class Account{
    private:
        int balance;
        static int roi;// we initilized but not allocated memory
    public:
        void setBalance(int b){
            balance = b;
        }
        void getData(){
            cout<<"roi "<<roi<<" , "<<"balance"<<balance<<endl;
        }
};
//nessessary to allocate memory
int Account::roi = 5;
int main(){
    Account a1;
    a1.setBalance(500);
    a1.getData();
}



#include <iostream>
using namespace std;
class Account{
    public:
        int balance;
        static int roi;// we initilized but not allocated memory
        void setBalance(int b){
            balance = b;
        }
        void getData(){
            cout<<"roi "<<roi<<" , "<<"balance"<<balance<<endl;
        }
};
// //nessessary to allocate memory
int Account::roi = 5;
int main(){
    Account a1;
    a1.roi = 7;
    a1.setBalance(500);
    a1.getData();
}

//op roi 7 , balance500