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
// class Solution {
//     private:
//     TreeNode* first;
//     TreeNode* middle;
//     TreeNode* last;
//     TreeNode* prev;
//     void Inorder(TreeNode* node){
//         if(node==NULL) return ;
//         Inorder(node->left);
//         if (prev!=NULL && prev->val>node->val){
//             if(first==NULL){             //first violation
//                 first=prev;
//                 middle=node;
//             }else last=node;                //second violation
//         }
//         prev=node;
//         Inorder(node->right);
//     }
// public:
//     void recoverTree(TreeNode* root) {
//         first=NULL;last=NULL;middle=NULL;
//         prev=new TreeNode(INT_MIN);
//         Inorder(root);
//         if(first && last) swap(first->val,last->val);
//         else if(first,middle) swap(first->val,middle->val);
//     }
// };