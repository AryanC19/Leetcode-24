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
    string path(TreeNode * root){

        if(root==NULL) return "#";

        string left= path(root->left);
        string right=path(root->right);
        // "^" vv imp, prefix boundary to save from
        // 12#1#1 , and 2#1#1 . now ^12#1#1, and ^2#1#1 , mismatch at 2!=1
        return "^"+to_string(root->val)+","+left+","+right;
    }
    bool isSubtree(TreeNode* rt, TreeNode* subRt) {
        string root=path(rt);
        string subRoot=path(subRt);
        int i=0;
        while(i<root.size()){
            int j=0;
            if(subRoot[j]==root[i]){
                int t_i=i;
                while(j< subRoot.size() && t_i < root.size() && subRoot[j]==root[t_i]){
                    t_i++;
                    j++;
                }
            }else{
                j=0;
            }
            if(j==subRoot.size()) return true;
            i++;
        }
        return false;

    }
};