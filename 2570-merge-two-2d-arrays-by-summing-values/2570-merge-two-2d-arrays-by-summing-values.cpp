class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        map<int,int > mp1;


        for(auto i:nums1){

            int id=i[0];
            int val=i[1];
            mp1[id]=val;
        }

        for(auto i:nums2){
            int id=i[0];
            int val=i[1];
            mp1[id]+=val;            
        }

        vector<vector<int> > ans;

        for(auto it:mp1){
            ans.push_back({it.first,it.second});
        }
        return ans;


    }
};