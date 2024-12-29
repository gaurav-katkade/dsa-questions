#include<iostream>
using namespace std;
//iterative fibonnaci
void fib(int n){
    if(n==0) return;
    int a = 0;
    if(n>=1){
        cout<<0<<" ";
    }
    n--;
    int b = 1;
    if(n>=1){
       cout<<1<<" "; 
    }
    n--;
    while(n>0){
        int c = a+b;
        a = b;
        b = c;
        cout<<c<<" ";
        n--;
    }
}
int main(){
    fib(2);
}

//Prepinsta solution
#include<iostream>
using namespace std;
int fib(int n){
    if(n<=1){
        cout<<n<<" ";
        return n;
    }
    int a = fib(n-1);
    int b = fib(n-2);
    cout<<a+b<<" ";
    return a+b;
}
int main(){
    cout<<fib(5);
}