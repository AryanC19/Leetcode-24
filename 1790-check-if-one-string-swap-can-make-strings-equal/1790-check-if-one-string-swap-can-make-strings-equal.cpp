class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        

        int n=s1.size();
        int m=s2.size();

        if(n!=m) return false;

        int i=0;

        char one='Z',two='Z';
        int cnt=0;

        bool oneSwap=false;

        while(i<n){
            if(s1[i]!=s2[i]){
                cnt++;
                if(cnt>2) return false;
                
                if(one=='Z' && two =='Z'){
                    one=s1[i];//r
                    two=s2[i];//b
                }else{
               

                    if(s1[i]==two && s2[i]==one){ 
                          
                        oneSwap=true;
                    }
                }
               
            }
            i++;
        }
        
        return s1==s2?true:oneSwap;
    }
};