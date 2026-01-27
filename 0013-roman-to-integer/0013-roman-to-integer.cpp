class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> romToInt;
            int ans=0;
        romToInt['I']=1;
        romToInt['V']=5;
        romToInt['X']=10;
        romToInt['L']=50;
        romToInt['C']=100;
        romToInt['D']=500;
        romToInt['M']=1000;
        for(int i=0;i<s.size();i++){

            if(romToInt[s[i]] < romToInt[s[i+1]]){
                ans-=romToInt[s[i]];
            }else{
                ans+=romToInt[s[i]];
            }
        }
        return ans;
    }
};