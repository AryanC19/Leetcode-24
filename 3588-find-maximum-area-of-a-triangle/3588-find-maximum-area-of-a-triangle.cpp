class Solution {
public:

    typedef long long ll;
    
    long long maxArea(vector<vector<int>>& coords) {
         
            
        //sort(coords.begin(),coords.end());
        unordered_map<int, pair<int,int> > xToy, yTox;

        for(auto coord:coords){

            xToy[coord[0]].first=INT_MAX;
            xToy[coord[0]].second=INT_MIN;

            yTox[coord[1]].first=INT_MAX;
            yTox[coord[1]].second=INT_MIN;
        }

        
        
        auto comp=[&](vector<int> a, vector<int> b){
            return a[1]<b[1];
        };
        
        int n=coords.size();
        // sort in ascednign based on first x then y
        // sort(xSort.begin(), xSort.end());
        // sort(ySort.begin(), ySort.end(), comp);
        int xMin=INT_MAX;
        int xMax=INT_MIN;
        //cout<< xMin<< " "<< xMax<<endl;

        
        int yMin=INT_MAX;
        int yMax=INT_MIN;

        //cout<< yMin<<" "<< yMax<<endl;

        for(auto &coord:coords){
            xMin=min(xMin, coord[0]);
            xMax=max(xMax,coord[0]);
            xToy[coord[0]].first=min(xToy[coord[0]].first, coord[1]);
            xToy[coord[0]].second=max(xToy[coord[0]].second, coord[1]);

            yMin=min(yMin, coord[1]);
            yMax=max(yMax,coord[1]);
            yTox[coord[1]].first=min(yTox[coord[1]].first, coord[0]);
            yTox[coord[1]].second=max(yTox[coord[1]].second, coord[0]);
        }

        // for(auto &coord:coords){

        // }


        

        ll ans=INT_MIN;
//gpt this bs below             
// vertical‐base triangles (base = vertical segment at x)
for (auto & [x, range] : xToy) {
    ll base = range.second - range.first;      // maxY - minY
    if (base > 0) {
        ll height = max( (ll)abs(x - xMin),
                         (ll)abs(x - xMax) );
        ans = max(ans, base * height);
    }
}

// horizontal‐base triangles (base = horizontal segment at y)
for (auto & [y, range] : yTox) {
    ll base = range.second - range.first;      // maxX - minX
    if (base > 0) {
        ll height = max( (ll)abs(y - yMin),
                         (ll)abs(y - yMax) );
        ans = max(ans, base * height);
    }
}
        return (ans==INT_MIN || ans==0) ?-1:ans;
    }
};