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
    bool func(TreeNode* root, int targetSum,int sum){

        if(root==NULL) return false;
        sum+=root->val;
        if(root->left==NULL && root->right==NULL  && targetSum==sum){
            return true;
        }
        bool left=func(root->left,targetSum,sum);
        bool right=func(root->right,targetSum,sum);
        return left||right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return func(root,targetSum,0);
    }
};