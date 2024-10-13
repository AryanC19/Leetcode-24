class Solution {
public:
    static bool comp(pair<int,int> &a,pair<int,int> &b){
        return a.second==b.second ? a.first>b.first : a.second >b.second;
    }


    int findxsum(unordered_map<int,int> &mpp,int x){

        
        vector<pair<int,int>> freq;

        for(auto i: mpp){
            freq.push_back({i.first,i.second});
        }
        sort(begin(freq),end(freq),comp);

        int xsum=0;

        //was missing the min(x, freq.size()) in contest, had to copy. rest code was fine. when there were lesser than x ele i was geting runtime error

        /*
            this satsisfies, this 
            Note that if an array has less than x distinct elements, its x-sum is the sum of the array.
            ie if freq.size() <x , we will consider all elemenst in freq, else we will consider the top x elements.
        */
        for(int i = 0; i < min(x, (int)freq.size()); i++) {
            xsum += freq[i].first * freq[i].second;
        }
        return xsum;
    }

    // optimized, using one map and sending it to calc xval instead of making an array again and again. improves tc
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        
        int l=0,r=k;
        int n=nums.size();
        unordered_map<int,int> mpp;

        for(int i=0;i<k;i++){
            mpp[nums[i]]++;
        }
        ans.push_back(findxsum(mpp,x));

        while(r<n){
            mpp[nums[r]]++;
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0) mpp.erase(nums[l]);
            ans.push_back(findxsum(mpp,x));
            r++;l++;
        }

        return ans;
        
    }
};



/*
Time Complexity (TC):

For each subarray (window), we do the following operations:
Update the frequency map: O(1)
Convert map to vector: O(k)
Sort the vector: O(k log k)
Calculate x-sum: O(min(x, k))
We perform these operations for each of the n-k+1 windows.
Therefore, the overall time complexity is O((n-k+1) * (k + k log k)) ≈ O(n * k log k), where n is the length of the input array.

Space Complexity (SC):

Frequency map (mpp): O(k) - stores at most k elements (the window size)
Vector for sorting (freq): O(k) - at most k elements from the map
Answer vector (ans): O(n-k+1) - stores the result for each window
The overall space complexity is O(k + (n-k+1)) ≈ O(n), as k ≤ n.

To summarize:

Time Complexity: O(n * k log k)
Space Complexity: O(n)
*/