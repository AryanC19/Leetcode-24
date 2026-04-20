class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n= colors.size();



        int i=0,j=n-1;
        int maxDist=0;

        while(i<j && colors[i]==colors[j]){
            i++;
        }
        maxDist=max(maxDist, j-i);

        i=0,j=n-1;
        while(i<j && colors[i]==colors[j]){
            j--;
        }
        maxDist=max(maxDist, j-i);
        
        return maxDist;
    }
};