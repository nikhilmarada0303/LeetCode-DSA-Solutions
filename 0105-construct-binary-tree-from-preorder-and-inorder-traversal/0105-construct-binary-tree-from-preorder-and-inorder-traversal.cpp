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
    TreeNode* consTree(int preStart,int preEnd,vector<int>&preorder,int inStart,int inEnd,vector<int>&inorder,map<int,int>&mp){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inRoot=mp[root->val];
        int left=inRoot-inStart;
        root->left=consTree(preStart+1,preStart+left,preorder,inStart,inRoot-1,inorder,mp);
        root->right=consTree(preStart+left+1,preEnd,preorder,inRoot+1,inEnd,inorder,mp);
        return root;   
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        TreeNode* root=consTree(0,preorder.size()-1,preorder,0,inorder.size()-1,inorder,mp);
        return root;
    }
};