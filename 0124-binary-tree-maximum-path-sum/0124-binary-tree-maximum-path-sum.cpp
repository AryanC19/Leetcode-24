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

    int func(TreeNode * root, int &ans){

        if(root==NULL) return 0;

        int ls=func(root->left,ans);
        int rs=func(root->right,ans);

        ans=max(ans,root->val+ls+rs);
        return max(0,root->val+max(ls,rs));
    }

    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        func(root,ans);
        return ans==INT_MIN ? 0:ans;
    }
};