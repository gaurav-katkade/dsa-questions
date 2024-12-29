class Solution {
public:
    vector<vector<int>> ans;
    void combinations(int n,int k,int i,vector<int> &arr){
        if(arr.size()==k){
            ans.push_back(arr);
            return;
        }
        for(int j=i;j<=n;j++){
            arr.push_back(j);
            combinations(n,k,j+1,arr);
            arr.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        combinations(n,k,1,temp);
        return ans;
    }
};