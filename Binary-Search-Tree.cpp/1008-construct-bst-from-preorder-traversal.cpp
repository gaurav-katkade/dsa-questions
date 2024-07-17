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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        TreeNode * root = constructBST(i,INT_MAX,preorder,preorder.size());
        return root;
    }
    TreeNode* constructBST(int& i,int ub,vector<int>& preorder,int n){
        if(i==n || preorder[i]>ub)return NULL;
        TreeNode* newnode = new TreeNode(preorder[i++]);
        newnode->left = constructBST(i,newnode->val,preorder,n);
        newnode->right = constructBST(i,ub,preorder,n);
        return newnode;
    }
};