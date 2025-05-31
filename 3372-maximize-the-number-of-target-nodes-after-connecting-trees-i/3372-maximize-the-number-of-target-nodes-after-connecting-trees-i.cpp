class Solution {
public:
// to calcualte for each hnode in tree1 whats the max no of target nodes in 
// tree1 itself 
    int dfs(int node, unordered_map<int,vector<int>> &adjList,vector<int> &vis,int k){

        if(k<0) return 0;
        vis[node]=1;

        int count=1;
        // remember theyre askign for COUNT, was taking maxNodes before. also initialize with one since node is self counted as well 
        for(auto child:adjList[node]){
            if(!vis[child])
                count+= dfs(child, adjList,vis, k-1);
        }
        return count;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        

/*first, precompute the MAX no. of nodes yuo can achieve from connecting any
node in tree1 to any node in tree2. 

for the MAX, well have to compute only once since we need to run one travesal through tree 2 to determine which node has the max weight at a sidtance of k-1, so store in variable maxK_1, meaning max k-1 from tree 2. 

Can use same DFS for both , remeber to USE VIS ARRAY for avoiding cycles since UNDIRECTED GRAPH. 


TC:

wrost case ,

each tree being chain , tc will be K is the depth
since running dfs TILL DEPTH K on N1 nodes , 

Tree1: n1 *k
Tree2: n2 *k

tc: k* (n1+n2)

sc: 
adjLists: n1+n2
vis arr : n1+n2
~ n1+n2
*/
    
        int n1=edges1.size()+1;

        int n2=edges2.size()+1;

        unordered_map<int,vector<int>  > adjList1,adjList2;
        

        for(auto it: edges1){

            int u=it[0];
            int v=it[1];

            adjList1[u].push_back(v);
            adjList1[v].push_back(u);
        }

        for(auto it: edges2){

            int u=it[0];
            int v=it[1];

            adjList2[u].push_back(v);
            adjList2[v].push_back(u);
        }

        vector<int> maxSelf(n1);
        int maxK_1=-1;
        

        for(int i=0;i<n1;i++){
            vector<int > vis1(n1);
            maxSelf[i]=dfs(i,adjList1,vis1, k);
        }
        

        for(int i=0;i<n2;i++){
            vector<int> vis2(n2);
            maxK_1=max(maxK_1,dfs(i,adjList2,vis2, k-1));
        }
        vector<int> ans(n1);

        for(int i=0;i<n1;i++){
            ans[i]=maxSelf[i]+maxK_1;   
        }

        return ans;        

    }
};