class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        

        
        int n=s1.size();
        int n2=s2.size();
        map<char,int> mpp1,mpp2;

        if (n > n2) return false; 

        for(auto i:s1) mpp1[i]++;

        for(int i=0;i<n;i++){
            mpp2[s2[i]]++;
        }

        int l=0,r=n;

        //if (mpp1 == mpp2) return true;
     
        while(r<n2){
            if(mpp1==mpp2) return true;
            mpp2[s2[r]]++;
            mpp2[s2[l]]--;

            if(mpp2[s2[l]]==0) mpp2.erase(s2[l]);

            l++;
            r++;
        }

        if(mpp1==mpp2) return true;

        return false;

    }
};
