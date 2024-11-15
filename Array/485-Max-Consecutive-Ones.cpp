class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxlen = INT_MIN;
        int cnt =0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                maxlen = max(cnt,maxlen);
                cnt = 0;
            }
            else if(nums[i]==1){
                cnt++;
            }
        }
        maxlen = max(cnt,maxlen);
        return maxlen;
    }
};