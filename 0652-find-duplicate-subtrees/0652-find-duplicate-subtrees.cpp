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

    unordered_map<string,int> freqMap;
    vector<TreeNode*> ans;
    
    string func(TreeNode* root){

        if(root==NULL) return "#";


        string left=func(root->left);
        string right=func(root->right);


        string s= to_string(root->val) + "," + left+ ","+right;

        if(freqMap[s]==1){
            ans.push_back(root);
        }

        freqMap[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        

        func(root);

        return ans;
    }
};