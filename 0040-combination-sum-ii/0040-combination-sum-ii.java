class Solution {
    
    public void func(int i, int[] candidates, int target,List<List<Integer>> ans , List<Integer> ds, int n){
        if(target==0){
            // vv imp , cannot simply add ds 
            ans.add(new ArrayList<>(ds));
        }
        if(i>=n|| target<0){
            return;
        }
        for (int j = i; j < n; j++) {
            if (j > i && candidates[j] == candidates[j-1]) continue; // skip duplicate
            ds.add(candidates[j]);
            func(j+1, candidates, target - candidates[j], ans, ds, n);
            ds.remove(ds.size()-1);
        }

    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans=new ArrayList<>();
        List<Integer> ds=new ArrayList<>();
        Arrays.sort(candidates);
        func(0,candidates, target, ans, ds, candidates.length);
        return ans;

    }
}