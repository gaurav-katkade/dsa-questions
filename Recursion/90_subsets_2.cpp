class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> sset;
        for(int i=0;i<pow(2,n);i++){ 
            vector<int> temp;
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            sort(temp.begin(),temp.end());
            sset.insert(temp);
        }
        vector<vector<int>> ans(sset.begin(),sset.end());
        return ans;
    }
};