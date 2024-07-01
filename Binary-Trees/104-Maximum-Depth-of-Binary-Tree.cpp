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

//__________________
// level order 
// _________________
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*>q;
        int level = 0;
        if(root == NULL)return 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                root = q.front();
                q.pop();
                if(root->left != NULL)q.push(root->left);
                if(root->right!= NULL)q.push(root->right);
            }
            level++;
        }
        return level;
    }
};