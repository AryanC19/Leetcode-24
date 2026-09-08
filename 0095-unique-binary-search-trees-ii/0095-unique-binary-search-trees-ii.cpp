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

    vector<TreeNode*> solve(int start, int end){
        // doesnt work with return {} , investigate why
        if(start>end) return {NULL};
        vector<TreeNode*> result;
        if(start==end){
            TreeNode* root=new TreeNode(start);
            return {root};
        }
        //fuzzy on how a tree is gettin gcreated, map it out in notes
        for(int i=start ;i<=end;i++){
            vector<TreeNode*> leftBSTs= solve(start,i-1);
            vector<TreeNode*> rightBSTs=solve(i+1,end);

            for(TreeNode* leftRoot : leftBSTs){
                for(TreeNode* rightRoot : rightBSTs){
                    TreeNode* root= new TreeNode(i);
                    root->left=leftRoot;
                    root->right=rightRoot;
                    result.push_back(root);
                }
            }
        }

        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};