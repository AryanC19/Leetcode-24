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

    bool isEvenOddTree(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        int lvl=0;

        while(!q.empty()){
            int size=q.size();
            bool isEven= lvl%2==0 ?1 :0;
            int prev=-1;
            while(size--){
                TreeNode* p=q.front();
                q.pop();
                if(isEven){
                    if(p->val%2==0 || (prev!=-1 &&  prev>= p->val)) return false;
                }else{
                    if(p->val%2!=0 || (prev!=-1 &&  prev<= p->val)) return false;
                }

                prev=p->val;
                if(p->left)  q.push(p->left);
                if(p->right) q.push(p->right);
            }
            lvl++;
        }
        return true;      
    }
};