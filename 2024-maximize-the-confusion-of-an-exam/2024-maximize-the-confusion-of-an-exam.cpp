class Solution {
public:
// max len of subarray with atmost k F's / T's

    int maxConsecutiveAnswers(string answerKey, int k) {

        int n=answerKey.size();
        int l=0,r=0;

        int ans=0;

        int F=0;
        while(r<n){
            F+= answerKey[r]=='F' ?1:0;
            while(F>k){
                F-=answerKey[l]=='F' ?1:0;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }

        int T=0;
        l=0,r=0;
        while(r<n){
            T+= answerKey[r]=='T' ?1:0;
            while(T>k){
                T-=answerKey[l]=='T' ?1:0;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }      

        return ans;

    }
};