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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>nodes;
        q.push({root,{0,0}});
        while(!q.empty()){
                auto temp = q.front();
                q.pop();
                int x = temp.second.first;
                int y = temp.second.second;
                nodes[x][y].insert(temp.first->val);
                if(temp.first->left!=NULL){
                    q.push({temp.first->left,{x-1,y+1}});
                }
                if(temp.first->right!=NULL){
                    q.push({temp.first->right,{x+1,y+1}});
                }
        }
        vector<vector<int>>ans;
        for(auto p:nodes){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};