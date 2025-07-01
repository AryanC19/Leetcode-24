class Solution {

 
    public int possibleStringCount(String word) {
        
        int n=word.length();
        int ans=1;
        int cnt=0;

        for(int i=1;i<n;i++){
            char c1=word.charAt(i);
            char c2=word.charAt(i-1);
            if(c1==c2){
                ans++;
            }
        }

        return ans;
    }
}