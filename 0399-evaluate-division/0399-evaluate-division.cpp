class Solution {
public:

    // void dfs( unordered_set<string>  &vis , unordered_map<string, vector<pair<string, double>>> &adjList,
    //     string src,string dst, double product, double &ans
    // ){
    //     if(vis.count(src)) return;

    //     vis.insert(src);

    //     if(src==dst){
    //         ans=product;
    //         return;
    //     }
    //     for(auto & child:adjList[src]){
    //         string childNode=child.first;
    //         double val=child.second;
    //         dfs(vis, adjList, childNode, dst, product * val, ans);
    //     }
    // }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();

        unordered_map<string, vector<pair<string, double>> > adjList;


        // construction of adjList with the inveted values
        for(int i=0;i<n;i++){
            string u=equations[i][0];
            string v=equations[i][1];
            double val=values[i];
            adjList[u].push_back({v,val});
            adjList[v].push_back({u,1.0/val});
        }

        // traversal

        vector<double> result;

        for(vector<string> &query:queries){

            string src=query[0];
            string dst=query[1];

            double ans=-1.0;
            
            if(adjList.count(src)){
                unordered_set<string> vis;
                //dfs(vis,adjList,src,dst,product,ans);
                // src,dst, product
                queue<pair<string,double>> q;
                q.push({src,1.0});
                while(!q.empty()){
                    auto [node, curr_product]=q.front();
                    q.pop();
                    vis.insert(node);
                    if(node==dst){
                        ans=curr_product;
                        break;
                    }
                    for(auto & child:adjList[node]){
                        string childNode=child.first;
                        double val=child.second;
                        if(!vis.count(childNode)){
                            q.push({childNode, curr_product*val});
                        }
                    }
                } 
            }

            result.push_back(ans);
        }

        return result;
    }
};