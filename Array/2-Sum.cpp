
//Hashing
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            auto it = mpp.find(target - nums[i]);
            if(it != mpp.end()){
                return {it->second,i};
            }
            mpp[nums[i]] = i;
        }
        return {0,0};
    }
};

//