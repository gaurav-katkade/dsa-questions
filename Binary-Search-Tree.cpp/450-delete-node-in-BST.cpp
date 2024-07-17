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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key) return helper(root);
        TreeNode* temp = root;
        while(root!=NULL){
            if(root->val < key){
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                }else{
                    root = root->right;
                }
            }else{
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                }else{
                    root = root->left;
                }
            }
        }
        return temp;
    }
    TreeNode* helper(TreeNode* root){
        //considering the edge of whe only left or right subtree
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;
        //find the inorder pressoror and replace with it 
        TreeNode* rootRight = root->right;
        //finding last  right most node of left subtree
        TreeNode* lastofLeft = findRightmost(root->left);
        lastofLeft->right = rootRight;
        return root->left;
    }
    TreeNode* findRightmost(TreeNode * root){
        while(root->right != NULL){
            root = root->right;
        }
        return root;
    }
};