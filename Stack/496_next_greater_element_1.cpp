class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>nge(m,-1);
        vector<int>result(n,-1);
        stack<int>stk;
        for(int i=m-1;i>=0;i--){
            while(!stk.empty()&&stk.top()<=nums2[i]){
                stk.pop();
            }
            if(!stk.empty()) nge[i] = stk.top();
            stk.push(nums2[i]);
        }
        for(int i=0;i<n;i++){
            auto it = find(nums2.begin(),nums2.end(),nums1[i]);
            int idx = it - nums2.begin();
            result[i] = nge[idx];
        }
        return result;
    }
};