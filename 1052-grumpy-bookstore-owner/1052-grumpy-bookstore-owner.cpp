class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int n=customers.size();
        int Unsatisfied=0;
        for(int i=0;i<minutes;i++){
            Unsatisfied+=customers[i]*grumpy[i];
        }

        int maxi=Unsatisfied;

        int i=0,j=minutes;

        while(j<n){
            Unsatisfied+=customers[j]*grumpy[j];
            Unsatisfied-=customers[i]*grumpy[i];    
            i++;
            j++;
            maxi=max(Unsatisfied,maxi);
        }
        int totalSatified=maxi;
        for(int i=0;i<n;i++){

            if(!grumpy[i]){
                totalSatified+=customers[i];
            }
        }
        return totalSatified;
    }
};