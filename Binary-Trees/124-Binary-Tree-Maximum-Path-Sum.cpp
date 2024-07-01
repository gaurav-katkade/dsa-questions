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
    int maxi = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(root==NULL)return 0;
        int val = findMaxPath(root);
        return max(maxi,val);
    }
    int findMaxPath(TreeNode* root){
        if(root==NULL)return 0;
        int leftSum = max(0,findMaxPath(root->left));
        int rightSum = max(0,findMaxPath(root->right));
        maxi = max(maxi,leftSum+rightSum+root->val);
        return root->val + max(leftSum,rightSum);
    }
};