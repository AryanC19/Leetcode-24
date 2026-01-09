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
    /*
    TreeMap-> Sorts keys
    Map /HashMap -> Unordered
    LinkedHashMap ->Insertion order preserved
     */
    public void dfs(TreeNode node, TreeMap<Integer,List<TreeNode>> depthMap, int depth){

        if(node==null) return;
        List<TreeNode> tempList=depthMap.getOrDefault(depth, new ArrayList<>());
        tempList.add(node);
        depthMap.put(depth, tempList);
        dfs(node.left, depthMap, depth+1);
        dfs(node.right, depthMap, depth+1);

    }


    public TreeNode LCA(TreeNode root,TreeNode node1, TreeNode node2){
        if(root==null) return null;
        if(root.val==node1.val || root.val==node2.val) return root;
        
        TreeNode left = LCA(root.left, node1, node2);
        TreeNode right = LCA(root.right, node1, node2);

        if(left!=null & right!=null) return root;
        if(left!=null) return left;
        return right;
    }


    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        // this is the same as LCA but instead of them giving us two nodes, 
        // we have n nodes based on a confition . condition being the furthest nodes from root

        
        //first, lets find the furthest nodes by doing a 1 pass bfs to populate depth map 
        TreeMap<Integer, List<TreeNode>> depthMap=new TreeMap<>();
        dfs(root, depthMap, 0);


        List<TreeNode> deepestNodes=new ArrayList<>();

        for(Map.Entry<Integer, List<TreeNode>> entry: depthMap.entrySet()){
            //System.out.print(entry.getKey()+":   ");
            deepestNodes=entry.getValue();
            //for(TreeNode t:entry.getValue()) System.out.print(t.val+","); 
            //System.out.println();
            
        }
        for(TreeNode t:deepestNodes) System.out.print(t.val+","); 
        //now that we have our depthMap, ie all the nodes at the deepest level , 
        // we have to find LCA for that List<TreeNodes> in the last depth . 



        if(deepestNodes.size()<2) return deepestNodes.get(0);
        TreeNode lcaNode= LCA(root,deepestNodes.get(0), deepestNodes.get(1));
        for(int i=2;i<deepestNodes.size();i++){
            lcaNode=LCA(root,lcaNode,  deepestNodes.get(i));    
        }
        return lcaNode;

    }
}