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
    TreeNode* func(TreeNode* node,TreeNode* p,TreeNode* q){
        if(node==NULL) return NULL;
        
        if(node->val>p->val && node->val>q->val) return func(node->left,p,q);
        if(node->val<p->val && node->val<q->val) return func(node->right,p,q);
        return node;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root==NULL || root==p || root==q) return root;
        
//         TreeNode* left=lowestCommonAncestor(root->left,p,q);
//         TreeNode* right=lowestCommonAncestor(root->right,p,q);
//         if(left==NULL) return right;
//         if(right==NULL) return left;
//         else return root;
        return func(root,p,q);
    }
};