class Solution {
public:


 /*
   
             1                 2         3       . .. . ... main for loop
 10  11  12 13 14     | 20           |30        recursion for loop with append
 100 110 120 . . . .  |  x           |x         recursion  "       "
 x   x    x           |              |
 
 */
    void solve(int i,vector<int> &ans,int n){

        if(i>n) return;
        ans.push_back(i);
        for(int append=0;append<=9;append++){
            int newnum=i*10+append;
            if(newnum>n) return;
            solve(newnum,ans,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        
        vector<int> ans;
        for(int i=1;i<=9;i++){
            solve(i,ans,n);
        }
        return ans;
    }
};