class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string ans="";
        if(encodedText.size()==0) return ans;
        int cols= (int) encodedText.size() / rows;


        vector<vector<char>> mat(rows,vector<char>(cols,' '));

        int charCount=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                mat[i][j]=encodedText[charCount];
                //cout<<encodedText[charCount]<<" ";
                charCount++;
            }
           // cout<<endl;
        }



        for(int tj=0;tj<cols;tj++){
            int ti=0;
            int ttj=tj;
            while(ti<rows && ttj<cols){
                ans+=mat[ti][ttj];
                ti++;
                ttj++;
            }
        }


        while(ans[ans.size()-1]==' ') ans.pop_back();

        return ans;
    }
};