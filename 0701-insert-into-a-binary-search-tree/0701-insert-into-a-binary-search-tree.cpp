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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=root;
        if(root==NULL) return new TreeNode(val);
        while(1){
            if(root->val<val){
                if(root->right!=NULL)
                    root=root->right;
                else{
                    root->right=new TreeNode(val);break;
                }
            }else{
                if(root->left!=NULL)
                    root=root->left;
                else{
                    root->left=new TreeNode(val);break;
                }
            }
        }return node;
    }
};