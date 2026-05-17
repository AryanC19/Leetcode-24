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
// tc, 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        // if the root is etiher of the 2 nodes return it
        if(root->val == p->val ||  root->val==q->val) return root;

        TreeNode* left =lowestCommonAncestor(root->left, p,q);
        TreeNode* right =lowestCommonAncestor(root->right, p,q);

        // if both my left and right subchild are !null, then i am the LCA
        if(left && right) return root;
        // if only my left subtree has a p or q, then i am not the LCA and i will sned this upwarwds
        else if(left) return left;
        //same as left
        else return right;
    }
};