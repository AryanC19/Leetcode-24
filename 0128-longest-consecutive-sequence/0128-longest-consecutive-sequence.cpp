class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();

        set<int> st;
        
        for(auto i:nums) st.insert(i);

        int cnt=0;
        int ans=0;

        for(auto it=st.begin();it!=st.end();it++){
            int cnt=1;
            int num=*it;
            if(!st.count(num-1)){
                while(st.count(num+1)){
                    cnt++;
                    num++;
                }
            }
            ans=max(ans, cnt);
        }
        return ans;
    }
};