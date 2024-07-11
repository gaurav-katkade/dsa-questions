/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void finding_parents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent_track[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root==NULL)return ans;
       unordered_map<TreeNode*,TreeNode*>parent_track;
        finding_parents(root,parent_track);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        q.push(target);
        int cur_lvl = 0;
        while(!q.empty()){
            int size = q.size();
            if(cur_lvl == k) break;
            cur_lvl++;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && visited[node->left]!=true){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && visited[node->right]!=true){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent_track[node] && visited[parent_track[node]]!=true){
                    q.push(parent_track[node]);
                    visited[parent_track[node]]=true;
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};