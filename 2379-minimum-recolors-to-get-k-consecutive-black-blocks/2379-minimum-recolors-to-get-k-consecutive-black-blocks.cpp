class Solution {
public:
    // find the minimum number of W blocks in a string of k B blocks
    int minimumRecolors(string blocks, int k) {
        

        int l=0,r=k;
        vector<int> freq(256,0);
        int n=blocks.size();
        for(int i=0;i<k;i++){
            freq[blocks[i]]++;
        }
        int ans=freq['W'];
        while(r<n){ 
            
            freq[blocks[r]]++;
            freq[blocks[l]]--;
            ans=min(ans,freq['W']);
            r++;
            l++;
        }
        return ans;
    }
};