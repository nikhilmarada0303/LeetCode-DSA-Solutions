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
/*
class Solution {
    private:
    void Inorder(TreeNode* node,vector<int>&v){
        if(node==NULL) return ;
        Inorder(node->left,v);
        v.push_back(node->val);
        Inorder(node->right,v);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        Inorder(root,v);
        int l=0;
        int h=v.size()-1;
        while(l<h){
            if(v[l]+v[h]==k) return true;
            else if(v[l]+v[h]<k) l++;
            else h--;
        }
        return false;
    }
};*/
class BSTiterator{
    stack<TreeNode*>st;
    bool reverse=true;
    public:
    BSTiterator(TreeNode* root,bool Isreverse){
        reverse=Isreverse;
        push(root);
    }
    int next(){
        TreeNode* topnode=st.top();
        st.pop();
        if(!reverse)
            push(topnode->right);
        
        else
            push(topnode->left);
        return topnode->val;
    }
    private:
    void push(TreeNode* node){
        while(node){
            st.push(node);
            if(!reverse) node=node->left;
            else node=node->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTiterator l(root,false);
        BSTiterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else
                j=r.next();
        }
        return false;
    }
};