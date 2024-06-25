class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int r=0,l=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(r<m && l<n){
            if(s[r]>=g[l]){
                l++;
            }
            r++;
        }
        return l;
    }
};