class Solution {
public:
    const long long MOD=1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        
        vector<int> arr(26,0);

        for(char i:s){
            arr[i-'a']++; 
        }
     
      //  cout<<endl;
        while(t--){
            vector<int> next(26,0);

            next[0]+=arr[25];
            next[1]+=arr[25];

            for(int i=0;i<25;i++){
                next[i+1]+=arr[i];
            }
            // for(auto i: arr){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            arr=next;
        }

        for(auto i: arr){
            cout<<i<<" ";
        }

        int ans=0;
        for(auto i:arr){
            ans= (ans+i)%MOD;
        }
        return ans;
    }
};