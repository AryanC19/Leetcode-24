class Solution {
    
    public void func(int i, int[] candidates, int target,List<Integer> temp,List<List<Integer>> ans){
        if(i>=candidates.length){
            if(target==0){
                ans.add(new ArrayList<>(temp));
            }
            return;
        } 
        if(target < 0) return;
        temp.add(candidates[i]);
        func(i, candidates, target -candidates[i], temp, ans);
        temp.remove(temp.size()-1);
        func(i+1, candidates, target , temp, ans);
    }
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans =new ArrayList<>();
        List<Integer> temp= new ArrayList<>();
        func(0,candidates, target, temp , ans);
        return ans;

    }
}