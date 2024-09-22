class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& banned) {
        
        unordered_map<string,int> mpp1;


        for(auto i:banned) mpp1[i]++;
        int cnt=0;
        for(auto i:message) {
            if(mpp1.find(i)!=mpp1.end()){
                cnt++;

                if(cnt>=2) return true;
            }
        }

        return false;
    }
};