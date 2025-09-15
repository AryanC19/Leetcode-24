class Solution {
    public void func(int i, int[] nums,int[] vis,List<List<Integer>> ans, List<Integer> ds){

        if(ds.size()==nums.length){
            ans.add(new ArrayList<>(ds));
            return;
        }

        if (i >= nums.length) return;
        if(vis[i]==0){
            vis[i]=1;
            ds.add(nums[i]);
            func(0, nums, vis, ans, ds);
            ds.remove(ds.size()-1);
            vis[i]=0;
        }
        func(i+1, nums, vis, ans , ds);
        
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer> >  ans= new ArrayList<>();
        List<Integer> ds= new ArrayList<>();
        int[] vis= new int[nums.length];
        func(0, nums , vis , ans, ds);
        return ans;
    }
}