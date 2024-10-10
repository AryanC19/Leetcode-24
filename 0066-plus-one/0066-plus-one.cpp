class Solution {
public:

    vector<int> plusOne(vector<int>& digits) {
        
        int n=digits.size();
        int unit=digits[n-1];
        
        if(unit<9){
            digits[n-1]++;
            return digits;
        }else{
            int i=n-1;
            while(i>=0 && digits[i] ==9){
                i--;
            }//   i      
            // 20539999
            if(i==-1){
                vector<int> ans(n+1,0);
                ans[0]=1;
                return ans;
            }else{
                digits[i]++;
                for(int j=i+1;j<n;j++){
                    digits[j]=0;
                }
            }
        }
        return digits;
    }
};