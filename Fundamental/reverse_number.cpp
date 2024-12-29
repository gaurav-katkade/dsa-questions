#include<iostream>
using namespace std;
int reverse_num(int n){
    int ans = 0;
    while(n>0){
        int var = n%10;
        ans = ans*10 + var;
        n = n/10;
    }
    return ans;
}
int main(){
    cout<<reverse_num(124);
}