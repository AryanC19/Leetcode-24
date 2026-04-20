class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int maxD=0;
        int n=colors.size();
        for(int i=0;i<n;i++){
            if(colors[i]!=colors[0]) maxD=max(maxD,i);
            if(colors[i]!=colors[n-1]) maxD=max(maxD,n-1-i);
        }
        return maxD;
    }
};