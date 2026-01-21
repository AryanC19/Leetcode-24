class Solution {
    boolean validCapacity(int capacity, int weights[], int days){
        //mip again, was off counting days by starting currDays=0. idiot stupid idiot 
        int currDays=1;
        int currCap=0;
        for(int i=0;i<weights.length;i++){
            int currWeight=weights[i];
            
            if(currCap+ currWeight > capacity){
                currDays++;
                currCap=currWeight;
            }else{
                currCap+=currWeight;
            }
            if(currDays>days) return false;
        }
        return currDays<=days;
    }
    public int shipWithinDays(int[] weights, int days) {
        // imp, forgot to take minCap as max of all weights
        int maxCapacity=0;
        int minCapacity=0;

        for(int i=0;i<weights.length;i++){ 
            maxCapacity+=weights[i];
            minCapacity = Math.max(minCapacity, weights[i]);
        }
        // tc : O n * sum(weights)
        // for(int capacity=minCapacity;capacity<=maxCapacity;capacity++){
            
        //     if(validCapacity(capacity, weights, days)) return capacity;
        // }

        // tc O n log sum(weights)
        int l=minCapacity,h=maxCapacity;
        int ans=maxCapacity;
        while(l<=h){

            int m= l+(h-l)/2;

            if(validCapacity(m, weights, days)){
                ans=Math.min(m,ans);
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
}