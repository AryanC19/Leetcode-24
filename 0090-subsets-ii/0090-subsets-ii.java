class Solution {
public void func(int start, List<Integer> ds, List<List<Integer>> ans, int[] nums) {
    ans.add(new ArrayList<>(ds));

    for (int i = start; i < nums.length; i++) {
        if (i > start && nums[i] == nums[i - 1]) continue; 

        ds.add(nums[i]);
        func(i + 1, ds, ans, nums);
        ds.remove(ds.size() - 1);
    }
}

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> ans=new ArrayList<>();
        List<Integer> ds= new ArrayList<>();
        Arrays.sort(nums);
        func(0,ds,ans,nums);
        return ans;
    }
}