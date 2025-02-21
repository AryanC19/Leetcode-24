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
class FindElements {
public:
    unordered_set<int> st;

    void dfs(TreeNode* root){

        if(root==NULL) return;

        int parent=root->val;

        st.insert(parent);

        int lval=2*parent +1;
        int rval=2*parent+ 2;

        
        if(root->left){
            root->left->val=lval;
            dfs(root->left);
        }

        if(root->right){
            root->right->val=rval;
            dfs(root->right);
        }
    }
    FindElements(TreeNode* root) {
        root->val=0;
        dfs(root);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */