https://leetcode.com/problems/permutation-in-string/submissions/1454035816/

class Solution {
public:
    bool flag = false;
    void generate_permutations(int i,string s1,string s2,int n){
        if(i==n){
            if(s2.find(s1)!=string::npos){
                flag = true;
            };
            return;
        }
        for(int j=0;j<n;j++){
            swap(s1[i],s1[j]);
            generate_permutations(i+1,s1,s2,n);
            swap(s1[i],s1[j]);
        }
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        generate_permutations(0,s1,s2,n);
        return flag;
    }
};