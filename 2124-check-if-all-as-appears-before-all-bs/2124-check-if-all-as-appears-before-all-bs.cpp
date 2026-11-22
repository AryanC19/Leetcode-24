class Solution {
public:
    bool checkString(string s) {
        bool bSeen=false;
        bool aSeen=false;


        for(char &c: s){
            if(c=='a'){
                if(bSeen) return false;
                aSeen=true;
            }
            if(c=='b') bSeen=true; 
        }

        return true;
    }
};