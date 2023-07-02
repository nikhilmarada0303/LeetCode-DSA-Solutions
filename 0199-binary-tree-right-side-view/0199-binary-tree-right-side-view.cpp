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
/*
class Solution {
    private:
    void func(TreeNode* node,int level,vector<int>&ans){
        if(node==NULL) return;
        if(level==ans.size()) ans.push_back(node->val);
        if(node->right) func(node->right,level+1,ans);
        if(node->left) func(node->left,level+1,ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        func(root,0,ans);
        return ans;
    }
};*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        if(root==NULL)
            return ans;
        while(!q.empty()){
          int size=q.size();
            int a=0;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                a=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(a);
        }return ans;
    }
};