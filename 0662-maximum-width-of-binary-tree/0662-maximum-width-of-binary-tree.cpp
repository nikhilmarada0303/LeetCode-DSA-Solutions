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
    int widthOfBinaryTree(TreeNode* root) {
         if(root==NULL) return 0;
        int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int m_min=q.front().second;
            int size=q.size();
            int first,last;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                long long curr_id=q.front().second-m_min;
                q.pop();
                if(i==0) first=curr_id;
                if(i==size-1) last=curr_id;
                if(node->left) q.push({node->left,curr_id*2+1});
                if(node->right) q.push({node->right,curr_id*2+2});
            }ans=max(ans,last-first+1);
        }return ans;
    
    }
};