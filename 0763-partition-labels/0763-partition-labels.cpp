class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> lastOcc;
        int n=s.size();

        for(int i=0;i<n;i++){
            lastOcc[s[i]]=i;
        }


        int i=0;

        vector<int> ans;

        while(i<n){

            int end= lastOcc[s[i]];

            int j=i;
            while(j<end){
                end=max(end,lastOcc[s[j]]);
                j++;
            }
            ans.push_back(j-i+1);
            i=j+1;
        }

        return ans;

    }
};