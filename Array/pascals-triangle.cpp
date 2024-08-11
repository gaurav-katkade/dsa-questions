class Solution {
public:
    vector<int> generateRow(int n){
        vector<int>row;
        int res = 1;
        row.push_back(res);
        for(int i=1;i<n;i++){
            res = res*(n - i);
            res = res/i;
            row.push_back(res);
        }
        return row;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i = 1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};