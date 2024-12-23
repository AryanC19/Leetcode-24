class Solution {
public:

    
    bool isValid(int r,int c,vector<vector<char>>& board){
        
        
        char num=board[r][c];
        // Column check
        for(int i = 0; i < 9; i++) {
            if(i != r && board[i][c] == num) return false;
        }
        
        // Row check
        for(int j = 0; j < 9; j++) {
            if(j != c && board[r][j] == num) return false;
        }
        
        
        //3x3 box
        
        int br=0,bc=0;
        
        if(r<3){
            br=0;
        }else if(r<6){
            br=3;
        }else{
            br=6;
        }
        
        if(c<3){
            bc=0;
        }else if(c<6){
            bc=3;
        }else{
            bc=6;
        }
        
        
        for(int i=br; i<br+3; i++) {
            for(int j=bc; j<bc+3; j++) {
                if(i==r && j==c) continue;
                if(board[i][j]==num) return false;
            }
        }
        
        return true;
        
    }
    
    
    
    bool isValidSudoku(vector<vector<char>>& board){
        
        
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c] != '.' && !isValid(r,c,board))  return false;   
            }
            
        }
        
        return true;
        
        
    }

};