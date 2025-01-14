
class Solution {
public:
    void func(TreeNode* root, int targetSum,int sum,vector<int> ds,vector<vector<int> > &ans){

        if(root==NULL) return;
        sum+=root->val;
        ds.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL  && targetSum==sum){
            ans.push_back(ds);
            return;
        }
        func(root->left,targetSum,sum,ds,ans);
        func(root->right,targetSum,sum,ds,ans); 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int> >ans;
        vector<int> ds;

        func(root,targetSum,0,ds,ans);
        return ans;
    }
};