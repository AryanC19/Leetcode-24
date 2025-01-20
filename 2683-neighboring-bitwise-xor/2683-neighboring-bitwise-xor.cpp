class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int num=0;
        for(auto i:derived) num^=i;
        return num==0;

    }
};