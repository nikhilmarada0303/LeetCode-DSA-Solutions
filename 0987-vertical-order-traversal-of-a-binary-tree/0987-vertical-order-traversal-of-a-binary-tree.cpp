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
/**  level order traversal
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //{node,{x axis , y axis }}
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int x_axis=q.front().second.first;
            int y_axis=q.front().second.second;
            q.pop();
            mp[x_axis][y_axis].insert(node->val);
            if(node->left) q.push({node->left,{x_axis-1,y_axis+1}});
            if(node->right) q.push({node->right,{x_axis+1,y_axis+1}});
        }
        vector<vector<int>>ans;
        for(auto p:mp){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }ans.push_back(col);
        }
        return ans;
    }
};*/
// inorder traversal
class Solution {
    private:
    void func(TreeNode* node,int x_axis,int y_axis, map<int,map<int,multiset<int>>>&mp){
        if(node==NULL) return ;
        mp[x_axis][y_axis].insert(node->val);
        if(node->left) func(node->left,x_axis-1,y_axis+1,mp);
        if(node->right) func(node->right,x_axis+1,y_axis+1,mp);
        
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
         map<int,map<int,multiset<int>>>mp;
        func(root,0,0,mp);
         for(auto p:mp){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }ans.push_back(col);
        }
        return ans;
    }
};