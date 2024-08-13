class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0;
        int  r = (n*m)-1;
        while(l<=r){
            int mid = (l+r)/2;
            int i = mid/m;
            int j = mid%m;
            if(target == matrix[i][j]){
                return true;
            }else if(target > matrix[i][j]){
                l = mid+1;
            }else{
                r = mid -1;
            }
        }
        return false;
    }
};