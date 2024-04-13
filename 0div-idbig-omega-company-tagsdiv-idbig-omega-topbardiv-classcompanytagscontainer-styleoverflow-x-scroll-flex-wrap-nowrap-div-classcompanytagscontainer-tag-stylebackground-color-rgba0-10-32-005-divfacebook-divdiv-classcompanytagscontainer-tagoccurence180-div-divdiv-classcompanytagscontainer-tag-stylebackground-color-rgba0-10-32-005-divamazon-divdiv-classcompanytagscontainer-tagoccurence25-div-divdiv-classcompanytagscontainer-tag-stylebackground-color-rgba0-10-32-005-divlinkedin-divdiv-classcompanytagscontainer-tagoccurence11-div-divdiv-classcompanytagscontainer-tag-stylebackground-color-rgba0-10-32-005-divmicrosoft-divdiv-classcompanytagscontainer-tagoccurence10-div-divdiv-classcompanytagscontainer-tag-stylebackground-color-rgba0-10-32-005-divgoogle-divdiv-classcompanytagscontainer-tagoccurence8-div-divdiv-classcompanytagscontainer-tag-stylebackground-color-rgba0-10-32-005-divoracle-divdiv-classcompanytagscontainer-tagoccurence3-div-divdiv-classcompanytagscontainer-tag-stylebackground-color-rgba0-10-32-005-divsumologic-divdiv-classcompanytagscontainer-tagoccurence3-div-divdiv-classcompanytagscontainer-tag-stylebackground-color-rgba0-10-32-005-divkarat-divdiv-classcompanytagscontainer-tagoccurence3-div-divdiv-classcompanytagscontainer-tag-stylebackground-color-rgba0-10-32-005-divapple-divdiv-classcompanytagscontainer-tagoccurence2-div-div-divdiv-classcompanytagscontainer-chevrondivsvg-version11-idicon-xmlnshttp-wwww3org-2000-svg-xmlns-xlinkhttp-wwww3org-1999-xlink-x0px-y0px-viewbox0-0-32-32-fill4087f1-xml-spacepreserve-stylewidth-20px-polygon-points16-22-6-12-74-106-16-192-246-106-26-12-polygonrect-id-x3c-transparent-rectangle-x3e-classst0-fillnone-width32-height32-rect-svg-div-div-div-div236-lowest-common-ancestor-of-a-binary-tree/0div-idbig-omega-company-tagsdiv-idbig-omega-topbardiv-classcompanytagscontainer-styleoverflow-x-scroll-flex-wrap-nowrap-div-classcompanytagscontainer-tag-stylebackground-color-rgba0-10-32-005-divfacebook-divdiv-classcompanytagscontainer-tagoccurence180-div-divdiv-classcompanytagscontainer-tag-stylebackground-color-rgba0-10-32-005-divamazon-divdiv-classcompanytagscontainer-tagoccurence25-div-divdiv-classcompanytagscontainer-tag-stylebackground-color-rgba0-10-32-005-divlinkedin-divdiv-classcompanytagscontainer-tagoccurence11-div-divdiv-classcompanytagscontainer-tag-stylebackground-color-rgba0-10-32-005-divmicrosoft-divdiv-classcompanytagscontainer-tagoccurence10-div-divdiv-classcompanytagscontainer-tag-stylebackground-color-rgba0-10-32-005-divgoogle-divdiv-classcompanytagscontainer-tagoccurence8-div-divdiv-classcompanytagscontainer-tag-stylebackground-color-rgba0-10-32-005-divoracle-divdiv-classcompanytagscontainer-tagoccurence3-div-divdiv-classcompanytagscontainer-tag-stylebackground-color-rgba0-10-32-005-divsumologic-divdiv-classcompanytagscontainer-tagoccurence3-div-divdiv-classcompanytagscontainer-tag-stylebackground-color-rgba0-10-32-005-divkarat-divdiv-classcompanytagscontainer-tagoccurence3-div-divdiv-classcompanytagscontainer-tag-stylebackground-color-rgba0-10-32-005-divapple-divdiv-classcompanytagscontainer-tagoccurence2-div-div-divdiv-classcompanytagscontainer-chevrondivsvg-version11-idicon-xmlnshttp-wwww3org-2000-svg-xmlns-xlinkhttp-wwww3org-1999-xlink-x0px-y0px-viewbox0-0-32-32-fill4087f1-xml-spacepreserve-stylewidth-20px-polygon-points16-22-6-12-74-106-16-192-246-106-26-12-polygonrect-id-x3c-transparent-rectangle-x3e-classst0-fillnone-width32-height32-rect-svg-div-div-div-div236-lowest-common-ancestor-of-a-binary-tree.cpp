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
    bool func(TreeNode* node,vector<TreeNode*>&v1,TreeNode* t){
        if(node==NULL) return 0;
        v1.push_back(node);
        if(node==t){
            return 1;
        }
        if(func(node->left,v1,t) || func(node->right,v1,t)) return 1;
        v1.pop_back();
        return 0;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // vector<TreeNode*>v1;
        // vector<TreeNode*>v2;
        // func(root,v1,p);
        // func(root,v2,q);
        // for(int i=0;i<min(v1.size(),v2.size());i++){
        //     if(v1[i]!=v2[i] && i>0){
        //         return v1[i-1];
        //     }
        // }return NULL;
         if(root==NULL || root==p || root==q)
            return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left==NULL) return right;
        else if(right==NULL) return left;
        else    // if both left,right are not NULL and we found our result
            return root;
    }
};