#include<iostream>
#include<algorithm>
using namespace std;
void bubble_sort(int* arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
            }
            
        }
    }
}
int main(){
    int n = 5;
    int* arr =new int[n]{4,9,10,7,3};
    bubble_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}