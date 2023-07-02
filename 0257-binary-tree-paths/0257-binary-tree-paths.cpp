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
    bool isLeaf(TreeNode* node){
     if(!node->left && !node->right) return true;
     return false;
 }
 void func(TreeNode* node,vector<string>&ans,string temp){
     if(node==NULL ) return ;
     if(isLeaf(node)){
          temp=temp+to_string(node->val);
         ans.push_back(temp);
     }
     temp=temp+to_string(node->val)+"->";
     func(node->left,ans,temp);
     func(node->right,ans,temp);
 }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp="";
        vector<string>ans;
        func(root,ans,temp);
        return ans;
    }
};