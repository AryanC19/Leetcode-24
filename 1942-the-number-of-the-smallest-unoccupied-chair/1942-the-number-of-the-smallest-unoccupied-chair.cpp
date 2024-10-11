class Solution {
public:

//brute force

    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        int n=times.size();
        int targetarrival=times[targetFriend][0];

        sort(begin(times),end(times));
        vector<int> chair(n,-1);
        for(auto i:times){    
            int arrive=i[0];
            int leaving=i[1];

            for(int i=0;i<n;i++){

                if(chair[i] <= arrive){
                    chair[i]=leaving;

                    if(arrive==targetarrival){
                        return i;
                    }
                    break;
                }
            }
            
        }
        return -1;
    }
};