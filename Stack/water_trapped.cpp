class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        vector<int>prefix(n,-1);
        vector<int>suffix(n,-1);
        prefix[0] = height[0];
        suffix[n-1] = height[n-1];
        for(int i=1;i<n;i++){
            if(height[i]>prefix[i-1]){
                prefix[i] = height[i];
            }else{
                prefix[i] = prefix[i-1]; 
            }
        }
        for(int i=n-2;i>=0;i--){
            if(height[i]>suffix[i+1]){
                suffix[i] = height[i];
            }else{
                suffix[i] = suffix[i+1]; 
            }
        }
        for(int i=0;i<n;i++){
            res += (min(prefix[i],suffix[i])-height[i]);
        }
        return res;
    }
};
//optimal : using two pointer approach
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int lmax = 0;
        int rmax = 0;
        int res = 0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>=lmax){
                    lmax = height[l];
                }else{
                    res += lmax-height[l];
                }
                l++;
            }else{
                if(height[r]>=rmax){
                    rmax = height[r];
                }else{
                    res += rmax-height[r];
                }
                r--;
            }
        }
        return res;
    }
};