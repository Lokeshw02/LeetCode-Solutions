class Solution {
public:
    
    bool canPlace(vector<vector<char>>& board, int i, int j, char num ){
        
        for(int idx = 0; idx < 9 ; idx++){
            //Row check 
            if(board[i][idx] == num) return false ;
            //Column Check 
            if(board[idx][j] == num) return false ;
            //Box Check 
            if(board[(i/3)*3 + (idx/3)][(j/3)*3 + idx%3] == num) return false ;
            
            
           
        }
        return true ;
                   
          

    }
    
    
    bool helper(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9 ; i++){
            for(int j = 0; j < 9 ; j++){
                
                if(board[i][j] == '.'){
                    
                    for(char num = '1'; num <= '9' ; num++){
                        
                        if(canPlace(board,i,j,num)) {
                            
                        board[i][j] = num ;
                        
                        if(helper(board)) 
                         return true ;
                            
                        board[i][j] = '.' ;
                        }
                    }
                    
                     return false ;
                }
               
            }
        }
        
        return true ;
        
    }
    
    
     void solveSudoku(vector<vector<char>>& board) {
       bool t =  helper(board) ;
         
     }
};