#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&,int,int,int);
void mergesort(vector<int>& arr,int l,int r){
    if(l>=r){
        return;
    }
    int mid = l + (r-l)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
void merge(vector<int>& arr,int l,int mid,int r){
    int i = l;
    int j = mid+1;
    vector<int> temp;
    while(i<=mid&&j<=r){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{https://www.onlinegdb.com/#tab-stdin
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=r){
        temp.push_back(arr[j]);
        j++;
    }
    for(int i=l;i<=r;i++){
        arr[i] = temp[i-l];
    }
}
int main(){
    vector<int> arr = {4,3,2,1};
    mergesort(arr,0,3);
    for(int i=0;i<4;i++){
        cout<<arr[i];
    }
}