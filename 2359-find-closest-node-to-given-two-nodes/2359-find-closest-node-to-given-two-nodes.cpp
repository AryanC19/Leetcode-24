class Solution {
public:





    typedef pair<int,int> P;
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {


        int n=edges.size();

        vector<int> n1(n,INT_MAX), n2(n,INT_MAX);
        n1[node1]=0;
        n2[node2]=0;
        // unordered_map<int,vector<int>  > adjList;
        // for(int i=0;i<n;i++){
        //     adjList[i].push_back(edges[i]);
        // }
        
        //priority_queue<P, vector<P> , greater<P> >  pq;
        queue<P> pq;
        //djistra for n1

        pq.push({0,node1});

        while(!pq.empty()){

            auto[dist,node]=pq.front();
            pq.pop();
            
            
            int child=edges[node];
            if(child==-1) continue;
            if(dist+1 < n1[child]){
                n1[child]=dist+1;
                pq.push({dist+1,child});
            }
        }

        pq.push({0,node2});
        
        while(!pq.empty()){

            auto[dist,node]=pq.front();
            pq.pop();
            int child=edges[node];
            if(child==-1) continue;
            if(dist+1 < n2[child]){
                n2[child]=dist+1;
                pq.push({dist+1,child});
            }
        }

        int d=INT_MAX;
        int idx=-1;



        // for(auto i:n1) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:n2) cout<<i<<" ";
        
        for(int i=0;i<n;i++){
            int maxi=max(n1[i],n2[i]);
            if(maxi<d){
                d=maxi;
                idx=i;
            }
        }
         return idx;
            
        
    }
};








