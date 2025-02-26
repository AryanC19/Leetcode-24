class Solution {
public:

    bool isValid(int r,int c,vector<string> &board,int n){

        int tr=r;
        int tc=c;

        // left
        while(tc>=0){
            if(board[tr][tc]=='Q') return false;
            tc--;
        }

        tr=r;
        tc=c;

        //leftbott

        while(tc>=0 && tr>=0){
            if(board[tr][tc]=='Q') return false;
            tc--;
            tr--;
        }

        tr=r;
        tc=c;

        //leftup
        while(tc>=0 && tr<n){
            if(board[tr][tc]=='Q') return false;
            tc--;
            tr++;
        }
        return true;
    }


    void solve(int col,vector<string> &board, vector<vector<string> > &ans,int n){

        if(col==n){
            ans.push_back(board);
            return ;
        }

        for(int row=0;row<n;row++){
            if(isValid(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }

    }


    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string> > ans;
        vector<string> board;
        string s(n,'.');

        
        for(int i=0;i<n;i++){
            board.push_back(s);
        }

        solve(0,board,ans,n);

        return ans;

    }
};