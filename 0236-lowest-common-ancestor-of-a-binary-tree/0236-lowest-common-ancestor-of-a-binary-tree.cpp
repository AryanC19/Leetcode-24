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
    
    void findPath(TreeNode* root, TreeNode* node,vector<TreeNode*> &path,bool &found){

        if(root==NULL || found) return ;

        path.push_back(root);

        if(root->val==node->val){found=true; return;}

        
        findPath(root->left,node,path,found);
        if(!found) findPath(root->right,node,path,found);
        
        if(!found) path.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       vector<TreeNode*> p1,q1;
       bool found=false;
       findPath(root,p,p1,found);
       found=false;
       findPath(root,q,q1,found);
       int i=0;
        while (i < p1.size() && i < q1.size() && p1[i]->val == q1[i]->val) {
            i++;
        }

        return p1[i-1];
    }
};