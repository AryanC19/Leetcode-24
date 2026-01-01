class Solution {
    public int[] plusOne(int[] digits) {
        
        int n=digits.length;

        boolean extraDigit=false;

        if(digits[n-1]==9){
            int i=n-1;
            while(i>=0 && digits[i]==9){
                digits[i]=0;
                i--;
            }
            if(i<0) extraDigit=true;
            else digits[i]++;
        }else{
            digits[n-1]++;
        }


        if(extraDigit==true){
            int[] ans= new int[n+1];
            ans[0]=1;

            for(int i=1;i<=n;i++){
                ans[i]=digits[i-1];
            }
            return ans;
        }

        return digits;
    }
}