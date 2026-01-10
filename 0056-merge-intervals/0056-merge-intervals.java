class Solution {
    public int[][] merge(int[][] intervals) {

        //imp :Java has no default comparator. so we have to cutom define what we want to sort a 2d arr on . 
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        List<int[]> mergedList=new ArrayList<>();

        // either merging or updating last el of last arr in List based on condition
        for(int[] interval:intervals){  
            int n=mergedList.size();
            if(mergedList.isEmpty() || mergedList.get(n-1)[1] < interval[0]){
                mergedList.add(interval);
            }else{
                mergedList.get(n-1)[1]=Math.max(mergedList.get(n-1)[1], interval[1]);
            }
        }

        //imp conversion of List<int[]> to int[][]
        int[][] ans = mergedList.toArray(new int[mergedList.size()][]);
        return ans;

    }
}