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
    // gloabl varialbe to determined if tree is balanced
    boolean balanced=true;

    public int getHeight(TreeNode root){
        if(root==null) return 0;
        int lh=getHeight(root.left);
        int rh=getHeight(root.right);
        // logic for balanced
        if(Math.abs(lh-rh) >1) balanced =false;
        // standard to get height of tree (height of deepest subtree)
        return 1+Math.max(lh,rh);
    }
    public boolean isBalanced(TreeNode root) {
        getHeight(root);
        return balanced;    
    }
}