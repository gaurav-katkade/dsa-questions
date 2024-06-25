class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n  = nums.size();
        int maxlen = 0;
        for(int i=0;i<n;i++){
            if(maxlen>=i){
                maxlen = max(maxlen,nums[i]+i);
            }else{
                return false;
            }
        }
        return true;
    }
};