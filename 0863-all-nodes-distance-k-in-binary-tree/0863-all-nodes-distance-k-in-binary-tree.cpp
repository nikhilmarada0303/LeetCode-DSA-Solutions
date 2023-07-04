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
    private:
     void parent_check(TreeNode* node,unordered_map<TreeNode*,TreeNode*>&parent_track){
         if(node==NULL) return ;
         if(node->left){
            parent_track[node->left]=node;
             parent_check(node->left,parent_track);
              
         }
         if(node->right){
            parent_track[node->right]=node;
             parent_check(node->right,parent_track);
              
         }
     }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        parent_check(root,parent_track);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited;
        q.push(target);
        visited[target]=true;
        int cnt=0;
        while(!q.empty()){
            int size=q.size();
            if(cnt==k) break;
            cnt++;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                 if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent_track[node] && !visited[parent_track[node]]){
                    q.push(parent_track[node]);
                    visited[parent_track[node]]=true;
                }
            }
        }
        vector<int>v;
        while(!q.empty()){
            v.push_back(q.front()->val);
            q.pop();
        }
        return v;
    }
};