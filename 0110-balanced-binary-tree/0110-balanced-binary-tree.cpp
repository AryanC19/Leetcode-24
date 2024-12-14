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


    // pair<pair<int,int> ,bool> helper(TreeNode* root){


    //     if(root==NULL) return {{0,0},false};


    //     int leftHeight=1+helper()

    // }



    

    int helper(TreeNode*root){

        if(root==NULL) return 0;
        int lh=helper(root->left);
        int rh=helper(root->right);
        return 1+max(lh,rh);   
    }

    bool isBalanced(TreeNode* root) {
        

        if(root==NULL) return true;


        int lh=helper(root->left);
        int rh=helper(root->right);

        bool leftBalanced=isBalanced(root->left);
        bool rightBalanced=isBalanced(root->right);


        return abs(lh-rh)<=1 && leftBalanced && rightBalanced;
    }
};