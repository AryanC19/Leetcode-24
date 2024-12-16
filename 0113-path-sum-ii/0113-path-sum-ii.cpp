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
    void solve(TreeNode* root, int targetSum,vector<vector<int>> &ans,vector<int> &ds){
        
        if(root==NULL) return ;
        ds.push_back(root->val);

        if(targetSum==root->val && root->left==NULL && root->right==NULL){
            ans.push_back(ds);
            
        }


        if(root->left)
            solve(root->left,targetSum-root->val,ans,ds);
        
        if(root->right)      
            solve(root->right,targetSum-root->val,ans,ds);
        
        ds.pop_back();
    
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(root,targetSum,ans,ds);
        return ans;
    }
};