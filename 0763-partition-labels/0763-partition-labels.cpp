class Solution {
public:
    vector<int> partitionLabels(string s) {

        // to store last_occ of every char
        unordered_map<char,int> last_occ;

        for(int i=0;i<s.size();i++){
            last_occ[s[i]]=i;
        }

        vector<int> res;
        int str=0,end=0;

/*
0123456789 10 11 12 13 14 15 16 17 18 19 20 21 22 23
ababcbacad e  f  e  g  d  e  h  i  j  h  k  l  i  j
                                                  i
s       e              e->e           e------->e->e
         s                e
                             s                    e
e=mx(0,lst_occ[a])
e=8
          5
e=mx(8,lst_occ[b])
e=8
.
.
.
e=8

i==e  , res.pb(8-0+1);
s=i+1; ,s=9;

i==e res.pb(15-9+1)
s=i+1 , s=16

i==e res.pb(23-16+1)


*/
        for(int i=0;i<s.size();i++){
            end=max(end,last_occ[s[i]]);
            if(i==end){
                res.push_back(end-str+1);
                str=i+1;
            }
                
        }
        return res;

    }
};