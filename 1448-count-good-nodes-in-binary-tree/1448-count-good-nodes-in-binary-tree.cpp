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
    int func(TreeNode* root,int val){

        if(root==NULL) return 0;
        int cnt=0;
        if(root->val >= val){ cnt=1;}
        return cnt+ (root->left?func(root->left, max(val,root->left->val)):0)+ (root->right?func(root->right,max(val, root->right->val)):0);
        
    }
    int goodNodes(TreeNode* root) {
        return func(root, root->val);
    }
};