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

    void func(TreeNode* root,TreeNode* p,vector<TreeNode*> &ds,bool &found){
        if(root==NULL ||found) return;
        ds.push_back(root);
        if(root==p){
            found=true;
            return;
        }
        func(root->left,p,ds,found);
        if(!found)func(root->right,p,ds,found);
        if(!found)ds.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> p1,q1;
        bool f1=false,f2=false;
        func(root,p,p1,f1);
        func(root,q,q1,f2);

        int i=0;
        while(i < p1.size() && i < q1.size()  && p1[i]==q1[i]) i++;
        i--;
        return p1[i];
    }
};