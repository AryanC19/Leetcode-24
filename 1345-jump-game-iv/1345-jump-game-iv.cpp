class Solution {
public:

// BFS tc O(N)
    int minJumps(vector<int>& arr) {

        int n=arr.size();
        queue<int> q;
        vector<int> vis(n,0);
        int minSteps=0;

        unordered_map<int,vector<int> > mpp;

        for(int i=0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }

        q.push(0);
        vis[0]=1;
        auto isValid=[&](int i){
            return i>=0 && i<n;
        };

        int steps=0;
        while(!q.empty()){

            int size=q.size();

            while(size--){

                int p=q.front();
                q.pop();

                if(p==n-1) return steps;
                // arr[i]==arr[j]
                for(int &num:mpp[arr[p]]){
                    if(isValid(num) && !vis[num]){
                        q.push(num);
                        vis[num]=1;
                    }
                }
                mpp.erase(arr[p]);

                // i-1
                if(isValid(p-1) && !vis[p-1]){
                    q.push(p-1);
                    vis[p-1]=1;
                }

                //i+1
                if(isValid(p+1) && !vis[p+1]){
                    q.push(p+1);
                    vis[p+1]=1;
                }
            }
            steps++;
        }
        return minSteps;
    }
};