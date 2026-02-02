class Solution {
public:
    string intToBin(int i){

        string bin="";
        while(i>0){
            if(i%2==0) bin+="1";
            else bin+="0";
            i/=2;
        }
        return bin;
    }
    bool isValid(string bin){
        if(bin.size()==1) return true;
        for(int j=1;j<bin.size();j++){
            if(bin[j]!=bin[j-1]) return false;
        }
        return true;
    }
    int countMonobit(int n) {
        int ans=0;

        for(int i=0;i<=n;i++){
            string bin=intToBin(i);
           // cout<<bin<<endl;
            if(isValid(bin)) ans++;
        }
        return ans;
    }
};