/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int num;
    vector<int> arr;
    cin>>num;
    int i = 0;
    while(num != 0){
        int val = num%10;
        arr.push_back(val);
        num = (num-val)/10;
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i];
    }
}