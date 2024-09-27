class Solution {
public:

    string convert(string s,int Rows)
    {   
        int n=s.size();
        
        if (Rows == 1 || Rows >= n) return s; // Edge case handling

        int ind = 0;
        vector<vector<char>>ans(Rows); 
        int dir = 1;

        for(auto ch : s)
        {
            ans[ind].push_back(ch);

            if(ind==Rows-1)
            {
                //change dir to upward
                dir = -1;
            }else if(ind == 0)
            {
                //chang dir to downward
                dir = 1;
            }

            ind+=dir;
        }
        string res = "";
        for(auto it: ans)
        {
            for(auto jt: it)
            {
            res+=jt;
            }
        }

        return res;
    }



};

