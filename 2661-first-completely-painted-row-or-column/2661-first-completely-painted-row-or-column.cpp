class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        cout<<"m,n:" << m << " "<< n <<endl;
        vector<int> rowCount(m),colCount(n);

        unordered_map<int,pair<int,int> > numToInd;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                numToInd[mat[i][j]]={i,j};
            }
        }

        for(int it=0;it<arr.size();it++){
           // cout<<"entered"<<endl;
            int num=arr[it];
            int i=numToInd[num].first;
            int j=numToInd[num].second;

            rowCount[i]+=1;
            colCount[j]+=1;

                // cout<<"rowCount " << it <<" "<<rowCount[i]<<endl;
                // cout<<"colCount " << it <<" "<<colCount[i]<<endl;
            if(rowCount[i]==n || colCount[j]== m){
                return it;
            }
        }
        return -1;
    }
};