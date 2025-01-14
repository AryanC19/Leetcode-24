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
    typedef long long ll;
    int total=0;
    void solve(TreeNode* root, int k,long long presum,unordered_map<ll,ll> &mpp){
        if(root==NULL) return;

        presum+=root->val;
        if(mpp.find(presum-k)!=mpp.end()){
            total+=mpp[presum-k];
        }
        mpp[presum]++;
        solve(root->left,k,presum,mpp);
        solve(root->right,k,presum,mpp);

        //missed this part, since were in recursion, we need to undo changes to mpp
        // and if mpp[pres]==0 erase it
        mpp[presum]--;
        if(mpp[presum]==0) mpp.erase(presum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        //          presum-freq
        unordered_map<ll,ll> mpp;
        //means a presum of 0 occurs 1 times ie no elemnt in subarr
        mpp[0]=1;
        solve(root,targetSum,0,mpp);
        return total;

    }
};