#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n = arr.size();
    unordered_map<int,int>mpp;
    int xxor = 0; 
    int count = 0;
    for(int i=0;i<n;i++){
        xxor = xxor^arr[i];
        if(xxor==x){
            count++;
        }
        int tofind = xxor^x;
        if(mpp.find(tofind)!=mpp.end()){
            count = count + mpp[tofind];
        }
        if(mpp.find(xxor)==mpp.end()){
            mpp[xxor] = 1;
        }else{
            mpp[xxor] = mpp[xxor] + 1;
        }
    }
    return count;
}