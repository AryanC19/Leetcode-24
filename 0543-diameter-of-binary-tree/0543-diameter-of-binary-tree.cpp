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
    int ans=0;  
    int func(TreeNode* root){

        if(root==NULL) return 0;


        int lh=func(root->left);
        int rh=func(root->right);


        ans=max(ans,lh+rh);
        return max(lh,rh)+1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        func(root);
        return ans;
    }
};