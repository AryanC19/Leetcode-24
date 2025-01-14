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

    int ans=INT_MIN;
    int func(TreeNode* root,int sum){

        if(root==NULL) return 0;
        sum+=root->val;
        int lsum=max(0,func(root->left,sum));
        int rsum=max(0,func(root->right,sum));
        ans=max(lsum+rsum+root->val,ans);
        return root->val + max(lsum, rsum);

    }
    int maxPathSum(TreeNode* root) {
    
        func(root,0);
        return ans;
    }
};