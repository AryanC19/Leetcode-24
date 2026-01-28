class DSU{
    public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        // 1 2  3 . .  .4 
        parent.resize(n+1,1);
        rank.resize(n+1);

        for(int i=1;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    int findParent(int x){
        if(x==parent[x]) return x;
        //path compression || rember to return func(parent[x])  not func(x)
        return parent[x]= findParent(parent[x]);  
    }
    void unionByRank(int x, int y){
        int x_parent=findParent(x);
        int y_parent=findParent(y);

        if(x_parent == y_parent) return;

        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent]=x_parent;
        }else if(rank[y_parent] > rank[x_parent]){
            parent[x_parent]=y_parent;
        }else{
            // boths rank were same , so we made either (x_parent in this case)
            // as parent, and increase its rank since we've just made it as parent
            parent[y_parent]=x_parent;
            rank[x_parent]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n);
        for(vector<int> &edge: edges){
            int u=edge[0];
            int v=edge[1];
            int u_parent=dsu.findParent(u);
            int v_parent=dsu.findParent(v);
            if(u_parent==v_parent) return edge;
            dsu.unionByRank(u,v);
        }

        return {};
    }
};