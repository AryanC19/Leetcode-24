/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root== nullptr) return nullptr;
        // if root queal p or q reutrn them since weve found
        if(root== p || root ==q) return root;

        // run dfs to search for left &  right
        TreeNode * left= lowestCommonAncestor(root->left, p, q);
        TreeNode * right= lowestCommonAncestor(root->right, p, q);
        // if my left & right nodes are NOT NULL, i am the lca 
        if(left && right) return root;
        // if right is null that means lca is in left subtree only
        if(left) return left;
        return right;
    }
};