#include<iostream>
#include<algorithm>
using namespace std;
struct Item{
    int value;
    int weight;
};
bool static comp(Item a,Item b){
    double fraction_val1 = (double)a.value/(double)a.weight;
    double fraction_val2 = (double)b.value/(double)b.weight;
    return fraction_val1 > fraction_val2;
}
int fractional_knapsack(int n,int w,Item arr[]){
    sort(arr,arr+n,comp);
    cout<<"arr[0].value"<<arr[0].value<<endl;
    int total_value = 0;
    for(int i=0;i<n;i++){
        if(arr[i].weight <= w){
            total_value += arr[i].value;
            w -= arr[i].weight;
        }else{
            cout<<"total_value"<<total_value<<" ";
            total_value += (arr[i].value/arr[i].weight)*w;
            w = 0;
            break;
        }
    }
    return total_value;
}
int main(){
   Item arr[] = {{100,20},{60,10},{120,30}};
   int answer = fractional_knapsack(3,50,arr);
   cout<<answer;
   return 0; 
}