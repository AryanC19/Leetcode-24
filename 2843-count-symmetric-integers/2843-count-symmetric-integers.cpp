class Solution {
public:
    bool isSymmetric(int i){


        string s=to_string(i);
        int n=s.size();

        if(n%2!=0) return false;


        string a= s.substr(0,n/2);
        string b=s.substr(n/2);


        int sa=0,sb=0;

        for(auto i:a){
            sa+= (i-'0');
        }

        for(auto i:b){
            sb+= (i-'0');
        }

        return sa==sb;

    }
    int countSymmetricIntegers(int low, int high) {


        int ans=0;

        for(int i=low;i<=high;i++){

            if(isSymmetric(i)) ans++;
        }    

        return ans;
    }
};