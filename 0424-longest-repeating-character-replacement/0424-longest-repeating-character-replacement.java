class Solution {
    public int characterReplacement(String s, int k) {
        
        int len=0;
        int n=s.length();


        for(int i=0;i<26;i++){

            char c= (char) ('A'+i);

            int l=0,r=0;

            int diff=0;

            while(r<n){

                if(s.charAt(r)!=c){
                    diff++;
                }

                while(l<r && diff>k){
                    if(s.charAt(l)!=c) diff--;
                    l++;
                }

                len=Math.max(len , r-l+1);

                r++;
            }
        }
        return len;
    }
}