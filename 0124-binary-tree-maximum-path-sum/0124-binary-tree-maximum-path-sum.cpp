/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int sum(TreeNode* node, int& ans) {

        if (node == NULL) {
            return 0;
        }

        int ls = max(0, sum(node->left, ans));

        int rs = max(0, sum(node->right, ans));

        ans = max(ans, node->val + ls + rs);

        return node->val + max(ls, rs);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        sum(root, ans);
        return ans;
    }
};