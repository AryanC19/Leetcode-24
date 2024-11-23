class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

        int m=box.size();
        int n=box[0].size();
        vector<vector<char>> ans(n,vector<char> (m));

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){
                ans[i][j]=box[j][i];

            }
        }
        for(auto &i: ans){
            reverse(begin(i),end(i));
        }
        //apply gravity
        for(int j=0;j<m;j++)
        {
            for(int i=n-1;i>=0;i--){

                if(ans[i][j]=='.'){
                   int stoneRow=-1;

                   for(int k=i-1;k>=0;k--){
                        if(ans[k][j]=='*'){
                            break;
                        }else if(ans[k][j]=='#'){
                            stoneRow=k;
                            break;
                        }
                   }

                   if(stoneRow!=-1){
                    ans[i][j]='#';
                    ans[stoneRow][j]='.';
                   }
                }

            }
        }


        // for(auto i:ans){

        //     for(auto j: i) cout<<j<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
};