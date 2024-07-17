/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool ans = validateBST(root,LONG_MIN,LONG_MAX);
        return ans;
    }
    bool validateBST(TreeNode* root,long a,long b){
        if(root==NULL)return true;
        if(!(a<root->val && root->val<b)){
            return false;
        }
        bool ans1 = validateBST(root->left,a,root->val);
        bool ans2 = validateBST(root->right,root->val,b);
        if(!(ans1 && ans2))return false;
        return true;
    }
};