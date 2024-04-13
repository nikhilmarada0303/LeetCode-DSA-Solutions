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
    void parent(TreeNode* root, map<TreeNode*,TreeNode*>&parentCheck){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front(); q.pop();
                if(node->left){
                    parentCheck[node->left]=node;
                    q.push(node->left);
                }
                if(node->right){
                    parentCheck[node->right]=node;
                    q.push(node->right);
                }
            }
        }return ;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>parentCheck;
        parent(root,parentCheck);
        map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        int cnt=0;
        vis[target]=1;
        q.push(target);
        while(!q.empty()){
            int size=q.size();
            if(cnt==k) break;
            cnt++;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(!vis[curr->left] && curr->left){
                    vis[curr->left]=1;
                    q.push(curr->left);
                }
                if(!vis[curr->right] && curr->right){
                    vis[curr->right]=1;
                    q.push(curr->right);
                }if(parentCheck[curr] && !vis[parentCheck[curr]]){
                    vis[parentCheck[curr]]=1;
                    q.push(parentCheck[curr]);
                }
            }
        }
        vector<int>v;
        while(!q.empty()){
            TreeNode* node=q.front();q.pop();
            v.push_back(node->val);
        }return v;
    }
};