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
    int value = -1;
    int K = -1;
    int cnt = 0;
    int kthSmallest(TreeNode* root, int k) {
        K = k;
        inorder(root); 
        return value;
    }
    void inorder(TreeNode* root){
        if(root==NULL)return;
        inorder(root->left);
        cnt++;
        if(cnt == K) value = root->val;
        inorder(root->right);
    }
};

////////////////////////////////////////////////////////////////
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
    int cnt = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)return -1;
        int value = inorder(root,k);
        return value;
    }
    int inorder(TreeNode* root,int k){
        if(root==NULL)return -1;
        int n = inorder(root->left,k);
        //
        if(n!=-1)return n;
        cnt++;
        if(cnt == k)return root->val;
        //
        int m = inorder(root->right,k);
        if(m!=-1)return m;
        return -1;
    }
};