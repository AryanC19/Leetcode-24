class Solution {
    public int minCost(String colors, int[] neededTime) {
        Stack<int[]> st=new Stack<>();

        int time=0;
        int i=0;

        for(char c:colors.toCharArray()){
            if(!st.isEmpty() && (char)st.peek()[1]== c ){

                if(neededTime[i]<=neededTime[st.peek()[0]]){
                    time+=neededTime[i];
                    i++;
                    continue;         
                }else{ // neededTime[i] > neededTime[st.peek()[0]]
                    time+=neededTime[st.peek()[0]];
                    st.pop();

                }
            }
            st.push(new int[]{i,c});
            i++;
        }
        return time;
    }
}