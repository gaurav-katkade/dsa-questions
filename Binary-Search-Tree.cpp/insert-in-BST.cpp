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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * curr = root;
        if(root == NULL) return new TreeNode(val);
        while(true){
            if(val >= curr->val){
                if(curr->right!=NULL){
                    curr = curr->right;
                }
                else{
                    TreeNode* newnode = new TreeNode(val);
                    curr->right = newnode;
                    break;
                }
            }else{
                if(curr->left!=NULL){
                    curr = curr->left;
                }else{
                    TreeNode * newnode = new TreeNode(val);
                    curr->left = newnode;
                    break;
                }
            }
        }
        return root;
    }
};