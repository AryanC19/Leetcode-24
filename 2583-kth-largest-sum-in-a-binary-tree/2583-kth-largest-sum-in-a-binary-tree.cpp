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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        queue<TreeNode*> q;
        q.push(root);

        priority_queue<ll,vector<ll>> pq;


        while(!q.empty()){


            ll size=q.size();

            ll sum=0;
            for(int i=0;i<size;i++){
                auto p=q.front();
                q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                sum+=p->val;
            }
            pq.push(sum);
        }

        ll ans=0;

        if(pq.size() <k) return -1;
        while(k-- && !pq.empty()){
            ans=pq.top();
            pq.pop();
        }

        return ans;
    }
};