class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int>mbb(256,-1);
        int right=0,left=0;
        int len = 0;
        while(right<n){
            if(mbb[s[right]]!=-1){
                left = max(left,mbb[s[right]]+1);
            }
            len = max(len,right-left+1);
            mbb[s[right]] = right;
            right++;
        }
        return len;
    }
};