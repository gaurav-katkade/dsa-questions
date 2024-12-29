#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> power_set(vector<int> &arr,int n){
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        int m = ans.size();
        for(int j=0;j<m;j++){
            vector<int> temp = ans[j];
            temp.push_back(arr[i]);
            ans.push_back(temp);
        }
        ans.push_back({arr[i]});
    }
    return ans;
}
int main(){
    vector<int> arr;
    string str;
    getline(cin,str);
    // cout<<str;
    stringstream ss(str);
    int num;
    while(ss>>num){
        arr.push_back(num);
    }
    // for(int i:arr){
    //     cout<<i;
    // }
    vector<vector<int>> ans = power_set(arr,arr.size());
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}