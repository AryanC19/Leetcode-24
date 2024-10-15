class Solution {
public:
    
    bool isValid(int row,int col,vector<string> &board, vector<vector<string>> &ans,int n){
        int duprow=row;
        int dupcol=col;
        //right diag up
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        row=duprow;
        col=dupcol;
        //left
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }   
        row=duprow;
        col=dupcol;

        //left diag down
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }   
        return true;

    }
    void solve(int col,vector<string> &board, vector<vector<string>> &ans,int n){
        
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isValid(row,col,board,ans,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s="";
        for(int i=0;i<n;i++) s+='.';
        for(int i=0;i<n;i++)board.push_back(s);    
        solve(0,board,ans,n);
        return ans;
    }
};