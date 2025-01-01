class Solution {
public:
    int maxScore(string s) {
        
        unordered_map<int,int> zeroLeft,oneRight;
        int n=s.size();

        if(s=="01") return 2;

        int lz=0,ro=0;

        int score=0;

        for(int i=1;i<n;i++){
            lz+= s[i-1]=='0' ?1 :0;
            zeroLeft[i-1]=lz;
        }

        for(int i=n-2;i>=0;i--){
            ro+= s[i+1]=='1' ?1 :0;
            oneRight[i+1]=ro;
        }


        for(int i=0;i<n;i++){
            cout<<zeroLeft[i]<< " "<< oneRight[i]<<endl;
            score=max(score,zeroLeft[i]+oneRight[i]);
        }

        return score;

    }
};