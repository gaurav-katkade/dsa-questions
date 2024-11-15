//Brute Force
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxcount  = 0;
        int n = s.size();
        unordered_set<char>sset;
        for(int i=0;i<n;i++){
            sset.clear();        
            int count = 0;
            for(int j=i;j<n;j++){
                if(sset.find(s[j])==sset.end()){
                    count++;
                    cout<<s[j]<<" ";
                    sset.insert(s[j]);
                }else{
                    break;
                }
            }
            maxcount = max(maxcount,count);
            cout<<endl;
        }
        return maxcount;
    }
};
//Better
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int maxlen = 0;
        unordered_set<char>sset;
        for(r =0;r<n;r++){
            if(sset.find(s[r])!=sset.end()){
                // cout<<"j";
                while(sset.find(s[r])!=sset.end()){
                    // cout<<" "<<s[l];
                    sset.erase(s[l]);
                    l++;
                }
            }
            sset.insert(s[r]);
            maxlen = max(maxlen,r-l+1);
        }
        return maxlen;
    }
};
//Optmial
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