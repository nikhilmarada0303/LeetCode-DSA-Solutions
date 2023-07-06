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
    private:
    void Inorder(TreeNode* node,vector<int>&v){
        if(node==NULL) return ;
        Inorder(node->left,v);
        v.push_back(node->val);
        Inorder(node->right,v);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        Inorder(root,v);
        int l=0;
        int h=v.size()-1;
        while(l<h){
            if(v[l]+v[h]==k) return true;
            else if(v[l]+v[h]<=k) l++;
            else h--;
        }
        return false;
    }
};