class Solution {
public:
    int fun(vector<int>&arr,int k){
        if(k<0)return 0;
        int n = arr.size();
        int sum =0,ans=0;
        int l=0,r=0;
        while(r<n){
            sum+=(arr[r]%2);
            while(sum>k){
                sum-=(arr[l]%2);
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       return fun(nums,k)-fun(nums,k-1);
    }
};