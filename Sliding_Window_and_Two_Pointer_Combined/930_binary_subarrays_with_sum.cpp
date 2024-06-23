class Solution {
public:
    int fun(vector<int>&nums,int goal){
        int n = nums.size();
        if(goal<0)return 0;
        int sum =0,ans=0;
        int l=0,r=0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fun(nums,goal)-fun(nums,goal-1);
    }
};