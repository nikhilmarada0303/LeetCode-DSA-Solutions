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
    TreeNode* func(TreeNode* node,int p,int q){
        if(node==NULL) return NULL;
        if(node->val<p && node->val<q) return func(node->right,p,q);
        if(node->val>p && node->val>q) return func(node->left,p,q);
        return node;    // this is condition for splitting
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return func(root,p->val,q->val);   
    }
};