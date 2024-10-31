class Solution {
public:
 vector<int> twoSum(vector<int> &arr, int k)
{

    int n = arr.size();
    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        int rem = k - arr[i];

        if (mpp.find(rem) != mpp.end())
        {
            return {i, mpp[rem]};
        }
        mpp[arr[i]]=i;
    }
    return {};
}
};