class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp=arr;
        sort(begin(temp),end(temp));

        unordered_map<int,int> mpp;
        int c=1;
        for(auto i:temp){
            if(!mpp.count(i))
                mpp[i]=c++;
        }

        vector<int>ans;

        for(auto i:arr){
            ans.push_back(mpp[i]);
        }
        return ans;
    }
};