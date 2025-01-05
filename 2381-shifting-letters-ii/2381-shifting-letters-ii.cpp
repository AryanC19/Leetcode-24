class Solution {
public:


/*
int main()
{
    

    cout<< "z+1 : " << char( ((('z' +1 +26) -'a')%26 )+'a') <<endl;
    

    cout<< "a-1: " << char(  ( ('a'-1 +26)-'a') % 26 + 'a' );
    return 0;
}
*/
    char normalize(int ch){
        ch = (ch -'a' +26) %26 +'a';
        return char(ch);
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {


        int n=s.size();

        vector<int> diffArr(n+1);

        //build diffArr
        for(auto &i :shifts){

            int L=i[0];
            int R=i[1];
            int dir=i[2];

            int x;

            if(dir==1){
                x=1;
            }else{
                x=-1;
            }

            diffArr[L] += x;    
            if(R+1 <n){
                diffArr[R +1] -=x; 
            }
        }  

        //cumsum

        int csum=0;
        for(int &num:diffArr){
            csum+=num;
            num=csum;
        }
        
        //applying shift
        string ans="";

        for(int i=0;i<n;i++){
            
           //wrap around case: 
           int shift=(diffArr[i]+26) %26;    
                        //chartoval //shift//wrap//backtochar
            s[i] = ( ( (s[i]-'a')+shift ) %26) +'a'; 
        }

        return s;
    }
};