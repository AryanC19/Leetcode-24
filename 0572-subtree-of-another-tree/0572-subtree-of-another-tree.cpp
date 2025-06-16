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

    string buildString(TreeNode* root){

        if(root==NULL) return "#";

        string left=buildString(root->left);
        string right=buildString(root->right);

        return to_string(root->val)+","+left+","+right;
    }
    void func(TreeNode* root, set <string> &st){
        if(root==NULL) return;
        st.insert(buildString(root));
        func(root->left,st);
        func(root->right,st);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        string needed=buildString(subRoot);
        set<string> st;

        func(root, st);

        return st.count(needed);
    }
};