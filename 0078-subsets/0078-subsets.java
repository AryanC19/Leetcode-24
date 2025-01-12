class Solution {

    public void func(int i,int[] nums,List<Integer> ds,List<List<Integer>> ans,int n){

        if(i>=n){
            return ;
        }
        ds.add(nums[i]);
        func(i+1,nums,ds,ans,n);
        ans.add(new ArrayList<>(ds));
        ds.remove(ds.size()-1);
        func(i+1,nums,ds,ans,n);
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans= new ArrayList<> ();
        List<Integer> ds=new ArrayList<> ();
        int n=nums.length;
        ans.add(new ArrayList<>()); //empty set
        func(0,nums,ds,ans,n);
        return ans;
    }
}