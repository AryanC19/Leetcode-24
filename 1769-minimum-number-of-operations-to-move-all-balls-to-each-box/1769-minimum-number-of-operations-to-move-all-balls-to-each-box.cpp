class Solution {
public:


/*\
      012345
      001011
left  001123
      
right 333221

     0       1        2     3       4       5
     0       0       1      0       1       1
{   {0}     {0}     {2}     {2}     {2,4}   {2,4,5}}
{   {2,5,4}{2,5,4}  {2,5,4} {5,4}   {5,4}   {5}}

     11|8|5|4|3|4
    [11,8,5,4,3,4]

*/
    vector<int> minOperations(string boxes) {
        
        int n=boxes.size();
        vector<vector<int>> pleft(n,vector<int> (0,0)),pright(n,vector<int> (0,0));
        vector<int> left,right;
        
        for(int i=0;i<n;i++){
            if(boxes[i]=='1'){
                left.push_back(i);
            }
            pleft[i]=left;
        }
        for(int i=n-1;i>=0;i--){

            if(boxes[i]=='1'){
                right.push_back(i);
            }
            pright[i]=right;
        }

        vector<int> ans(n);

        for(int i=0;i<n;i++){

            int minDist=0;

            for(auto &j :pleft[i]){
                minDist+= abs(i-j);
            }
            for(auto &j :pright[i]){
                minDist+= abs(i-j);
            }
            ans[i]=minDist;
        }

        return ans;
    }
};