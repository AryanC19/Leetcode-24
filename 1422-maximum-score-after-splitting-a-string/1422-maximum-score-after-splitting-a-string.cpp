class Solution {
public:
    int maxScore(string s) {
        
        unordered_map<int,int> zeroLeft,oneRight;
        int n=s.size();

     //   if(s=="01") return 2;

        int lz=0,ro=0;

        int score=0;

        for(int i=0;i<n-1;i++){
            lz+= s[i]=='0' ?1 :0;
            zeroLeft[i]=lz;
        }

        for(int i=n-1;i>0;i--){
            ro+= s[i]=='1' ?1 :0;
            oneRight[i]=ro;
        }


        for(int i=0;i<n-1;i++){
            cout<<zeroLeft[i]<< " "<< oneRight[i]<<endl;
            score=max(score,zeroLeft[i]+oneRight[i+1]);
        }

        return score;

    }
};