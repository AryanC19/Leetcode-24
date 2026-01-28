class Solution {
public:
    string getPermutation(int n, int k) {
        
        int fact=1;
        string ds="";
        //
        for(int i=1;i<n;i++){
            fact*=i;
            ds+=to_string(i);
        }
        ds+=to_string(n);
        string ans="";
        k--;
        while(true){
            ans.push_back(ds[k/fact]);
            ds.erase(ds.begin() + k/fact);
            if(ds.size()==0){
                break;
            }
            k=k%fact;
            fact=fact/ ds.size();
        }
        return ans;
    }
};