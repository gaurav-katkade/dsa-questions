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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>stk1;
        stack<TreeNode*>stk2;
        vector<int>postorder;
        if(root==NULL)return postorder;
        stk1.push(root);
        while(!stk1.empty()){
            root = stk1.top();
            stk1.pop();
            stk2.push(root);
            if(root->left!=NULL)stk1.push(root->left);
            if(root->right!=NULL)stk1.push(root->right);
        }
        while(!stk2.empty()){
            postorder.push_back(stk2.top()->val);
            stk2.pop();
        }
        return postorder;
    }
};

//Using single stack
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        stack<TreeNode*>stk;
        TreeNode* curr = root;
        while(curr!=NULL || !stk.empty()){
            if(curr!=NULL){
                stk.push(curr);
                curr = curr->left;
            }else{
                TreeNode* temp = stk.top()->right;
                if(temp==NULL){
                    temp = stk.top();
                    stk.pop();
                    postorder.push_back(temp->val);
                    while(!stk.empty() && temp == stk.top()->right){
                        temp = stk.top();
                        stk.pop();
                        postorder.push_back(temp->val);
                    }

                }else{
                    curr = temp;
                }
            }

        }
        return postorder;
    }
};