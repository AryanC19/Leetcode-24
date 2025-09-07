class Solution {
    public void func(){

    }
    public int[] sumZero(int n) {
        List<Integer> ansArr= new ArrayList<>();

        
        if(n%2!=0){
            ansArr.add(0);
        }

        int lastInt=n/2;

        for(int i=-lastInt;i<=0;i++){
            if(i==0) continue;
            ansArr.add(i);
            ansArr.add(-i);
        }

        return ansArr.stream().mapToInt(i -> i).toArray();
        
    }
}