class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0;
        int jumps = 0;
        while(r<nums.size()-1){
            int farmost = 0;
            for(int i=l;i<=r;i++){
                farmost = max(farmost,nums[i]+i);
            }
            l = r+1;
            r = farmost;
            jumps++;
        }
        return jumps;
    }
};