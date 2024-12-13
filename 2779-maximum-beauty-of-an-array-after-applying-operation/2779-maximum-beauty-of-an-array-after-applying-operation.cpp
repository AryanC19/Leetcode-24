class Solution {
public:
    typedef pair<int,int> P;

    int maximumBeauty(vector<int>& nums, int k) {


        int n=nums.size();

        vector<P> arr;

        for(auto i:nums){
            arr.push_back({i-k,i+k});
        }

        sort(begin(arr),end(arr));

        queue<P> q;
        int ans=0;
        

        for(auto i:arr){

            while(!q.empty() && q.front().second<i.first){
                q.pop();
            }
            q.push(i);

            ans=max(ans,(int)q.size());
        }
        return ans;




        

    }
};