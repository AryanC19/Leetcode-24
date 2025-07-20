class Solution {
public:
    static bool comp(vector<int> p1,vector<int> p2){
        return p1[1]<p2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        int cnt=1;
        int freetime=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] >=freetime){
                
                cnt++;
                freetime=intervals[i][1];
            }
        }
        cout<<cnt;
        return n-cnt;
    }
};
//        i
//[[1,2],[2,3],[1,3],[3,4]]