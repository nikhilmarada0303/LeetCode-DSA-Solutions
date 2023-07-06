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
class BSTIterator {
    private:
    void inorder(TreeNode* node,vector<int>&v){
        if(node==NULL) return;
        inorder(node->left,v);
        v.push_back(node->val);
        inorder(node->right,v);
    }
public:
    int i=0;
    vector<int>v;
    BSTIterator(TreeNode* root) {
        inorder(root,v);
    }
    
    int next() {
        return v[i++];
    }
    
    bool hasNext() {
        if(i<v.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */