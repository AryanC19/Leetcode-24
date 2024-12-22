class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        
        vector<vector<int>> xarr,yarr,ans1,ans2;


        for(auto i:rectangles){
            xarr.push_back({i[0],i[2]});
            yarr.push_back({i[1],i[3]});
        }

        sort(begin(xarr),end(xarr));
        sort(begin(yarr),end(yarr));

        //check for x parts

/*
Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]

xarr= {0,2}{2,4}{2,3}{4,5} 

ans1 ={0,2}
*/
        for(auto i:xarr){

            if(ans1.empty() || ans1.back()[1] <= i[0]){
                ans1.push_back(i);
            }else if(ans1.back()[1] > i[0]){
                ans1.back()[1]=max(ans1.back()[1],i[1]);
            }
        }

        for(auto i:yarr){

            if(ans2.empty() || ans2.back()[1] <= i[0]){
                ans2.push_back(i);
            }else if(ans2.back()[1] > i[0]){
                ans2.back()[1]=max(ans2.back()[1],i[1]);
            }
        }



        int n1=ans1.size();
        int m=ans2.size();

        return n1>=3 || m>=3;
    }
};