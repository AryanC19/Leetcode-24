class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        int tot=0;
        for(int i:apple) tot+= i;

        Arrays.sort(capacity);

        int box=0;
        int n=capacity.length;

        for(int i=n-1;i>=0;i--){
            tot-=capacity[i];
            box++;
            if(tot<=0) break;
        }
        return box;

    }
}