/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int maxDepth=-1;
    public void dfs(TreeNode node, Map<Integer, Integer> nodeDepth, int depth){
        if(node==null) return;
        nodeDepth.put(node.val, depth);
        maxDepth=Math.max(maxDepth,depth);
        dfs(node.left, nodeDepth, depth+1);
        dfs(node.right, nodeDepth, depth+1);
    }

    /* here , we manipulate the standard LCA code to return the node
       when the root ==maxDepth , instead of the standard when root==the deepest Node value. 

       This is a tricky optimzation that is hard to comeby on your own .
       if a node's left subtrees maxDepth == node;s right subtrees maxDepth, 
       that means that node is the LCA for the deepest leaves. 
       
       because if either of the depth of left or right subtrees were not same, 
       that means the subtree with longer depth is the one who possible has the LCA for the deepest nodes and the other tree is discared. 
       check diagram in notes for clarifty .
    */
    public TreeNode LCA(TreeNode root,Map<Integer, Integer> nodeDepth){
        if(root==null) return null;
        if(nodeDepth.get(root.val)==maxDepth) return root;
        
        TreeNode left = LCA(root.left, nodeDepth);
        TreeNode right = LCA(root.right, nodeDepth);

        if(left!=null & right!=null) return root;
        if(left!=null) return left;
        return right;
    }

    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        // this is the same as LCA but instead of them giving us two nodes, 
        // we have n nodes based on a confition . condition being the furthest nodes from root
        //first, lets find the furthest nodes by doing a 1 pass dfs to populate depth map 
        Map<Integer, Integer> nodeDepth=new HashMap<>();
        dfs(root, nodeDepth, 0);
        return LCA(root, nodeDepth);
    }
}