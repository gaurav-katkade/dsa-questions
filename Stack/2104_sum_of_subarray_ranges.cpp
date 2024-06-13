class Solution {
public:
    long long subArrayMin(vector<int>&nums){
        long long ans = 0;
        int n = nums.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<pair<int,int>>stk_left;
        stack<pair<int,int>>stk_right;
        for(int i=0;i<n;i++){
            int cnt = 1;
            while(!stk_left.empty()&&stk_left.top().first>nums[i]){
                cnt += stk_left.top().second;
                stk_left.pop();
            }
            stk_left.push({nums[i],cnt});
            left[i]=cnt;
        }
        for(int i=n-1;i>=0;i--){
            int cnt = 1;
            while(!stk_right.empty()&&stk_right.top().first>=nums[i]){
                cnt += stk_right.top().second;
                stk_right.pop();
            }
            stk_right.push({nums[i],cnt});
            right[i]=cnt;
        }
        for(int i=0;i<n;i++){
            ans += (long long)nums[i]*(long long)left[i]*(long long)right[i];
        }
        return ans;
    }
    long long subArrayMax(vector<int>&nums){
        long long ans = 0;
        int n = nums.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<pair<int,int>>stk_left;
        stack<pair<int,int>>stk_right;
        for(int i=0;i<n;i++){
            int cnt = 1;
            while(!stk_left.empty()&&stk_left.top().first<nums[i]){
                cnt += stk_left.top().second;
                stk_left.pop();
            }
            stk_left.push({nums[i],cnt});
            left[i]=cnt;
        }
        for(int i=n-1;i>=0;i--){
            int cnt = 1;
            while(!stk_right.empty()&&stk_right.top().first<=nums[i]){
                cnt += stk_right.top().second;
                stk_right.pop();
            }
            stk_right.push({nums[i],cnt});
            right[i]=cnt;
        }
        for(int i=0;i<n;i++){
            ans += (long long)nums[i]*(long long)left[i]*(long long)right[i];
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        return subArrayMax(nums)-subArrayMin(nums);
    }
};