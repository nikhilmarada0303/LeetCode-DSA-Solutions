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
    void func(TreeNode* node,vector<int>&v){
        if(node==NULL) return ;
        func(node->left,v);
        v.push_back(node->val);
        func(node->right,v);
    }
    void checkInorder(TreeNode* node,vector<int>&v,int &i){
        if(node==NULL) return ;
        checkInorder(node->left,v,i);
        if(node->val!=v[i]) swap(node->val,v[i]);
        i++;
        checkInorder(node->right,v,i);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int>v;
        func(root,v);
        sort(v.begin(),v.end());
        int i=0;
        checkInorder(root,v,i);
    }
};