class Solution {

    public int func(int i, int[] energy, int k, int n){
        if(i>=n) return 0;
        int eg= energy[i] + func(i+k,energy, k, n);
        return eg;
    }
    public int maximumEnergy(int[] energy, int k) {
        int ans=Integer.MIN_VALUE;
        for(int i=0;i<energy.length;i++){
            ans=Math.max(ans, func(i,energy,k,energy.length));
        }
        return ans;
    }
}