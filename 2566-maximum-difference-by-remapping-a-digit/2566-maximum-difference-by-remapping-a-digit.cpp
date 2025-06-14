class Solution {
public:
    int minMaxDifference(int num) {
        // 0 1 2 3 4 5 6 7 8 9
        //     6
        // 
        string maxi=to_string(num);
        string mini=to_string(num);
        int firstNonNine=-1, firstNonZero=-1;
        int minN=INT_MAX,maxN=INT_MIN;
        for(auto i: maxi){
            int digi=i-'0';
            if(firstNonNine==-1 && digi!=9) firstNonNine=digi;
            if(firstNonZero==-1 && digi!=0) firstNonZero=digi;
            
            minN=min(digi,minN);
            maxN=max(digi,maxN);
        }

        
        for(auto &i:maxi){
            int digi=i-'0';
            if(digi==firstNonNine) i='9';
        }
        for(auto &i:mini){
            int digi=i-'0';
            if(digi==firstNonZero) i='0';
        }

        int minNum=stoi(mini);
        int maxNum=stoi(maxi);

        return maxNum-minNum;

     }
};

