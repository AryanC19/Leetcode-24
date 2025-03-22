class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) { 

        int n=recipes.size();
         
        // ingredient, recipe
        unordered_map<string,vector<int> > adj;

        unordered_set<string> st ( supplies.begin(), supplies.end());

        vector<int> indegree(n,0);
         
        for(int i=0;i<recipes.size();i++){

            for(string &ing: ingredients[i]){

                if(!st.count(ing)){
                    adj[ing].push_back(i);
                    indegree[i]++;
                }
            }
        }
        queue<int> q;

        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }


        vector<string> ans;

        while(!q.empty()){

            int node=q.front();
            q.pop();
            string recipe=recipes[node];

            ans.push_back(recipe);

            for(auto &idx : adj[recipe]){
                indegree[idx]--;
                if(indegree[idx]==0) q.push(idx);
            }
   
        }

        return ans;

    }
};