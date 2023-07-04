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
    TreeNode* consTree(int postStart,int postEnd,vector<int>&postorder,int inStart,int inEnd,vector<int>&inorder,map<int,int>&mp){
        if(postStart>postEnd || inStart>inEnd) return NULL;
        TreeNode* root=new TreeNode(postorder[postEnd]);
        int inRoot=mp[root->val];
        int left=inRoot-inStart;
        root->left=consTree(postStart,postStart+left-1,postorder,inStart,inRoot-1,inorder,mp);
        root->right=consTree(postStart+left,postEnd-1,postorder,inRoot+1,inEnd,inorder,mp);
        return root;   
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        TreeNode* root=consTree(0,postorder.size()-1,postorder,0,inorder.size()-1,inorder,mp);
        return root;
    }
};