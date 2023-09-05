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
    int func(TreeNode* node){
        if(node==NULL) return 0;
        int left=func(node->left);
        int right=func(node->right);
         if(abs(left-right)>1) return -1;
        if(left==-1 || right==-1) return -1;
       
        return 1+max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
        return func(root)!=-1;
    }
};