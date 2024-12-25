class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        
        int n1=s1.size();
        int n2=s2.size();
        map<char,int> mpp1,mpp2;

        for(auto i:s1) mpp1[i]++;

        for(int i=0;i<n1;i++){
            mpp2[s2[i]]++;
        }
        vector<int> ans;
        int l=0,r=n1;
     
        while(r<n2){
            if(mpp1==mpp2) {
                ans.push_back(l);
            }
            mpp2[s2[r]]++;
            mpp2[s2[l]]--;

            if(mpp2[s2[l]]==0) mpp2.erase(s2[l]);

            l++;
            r++;
        }

        if(mpp1==mpp2) {
            ans.push_back(l);
        }

        

        return ans;
        
    }
};