class Solution {
public:
    
    int func(int i,int cb,int n){
        
        
        if(i==n){
            return 1;
        } 
        if(i>n) return 1e9;
        
        int paste=1+func(i+cb,cb,n);
        
        int copy=1e9;
        if(cb!=i){
            copy=1+func(i,i,n);
        }
        
        return min(copy,paste);
    }
    int minSteps(int n) {
        if(n==1) return 0;
        return func(1,1,n);
        
    }
};