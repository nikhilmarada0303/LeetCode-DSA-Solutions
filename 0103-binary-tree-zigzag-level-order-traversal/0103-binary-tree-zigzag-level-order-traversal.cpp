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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        bool LeftToRight=true;
        while(!q.empty()){
            int size=q.size();
            vector<int>row(size);
            for(int i=0;i<size;i++){
                 TreeNode* node=q.front();
                 q.pop();
                 row[i]=node->val;
                 if(node->left) q.push(node->left);
                 if(node->right) q.push(node->right);
                 
            }if(!LeftToRight){
                reverse(row.begin(),row.end());
            }
            LeftToRight=!LeftToRight;
            ans.push_back(row);
            
        }return ans;
    }
};