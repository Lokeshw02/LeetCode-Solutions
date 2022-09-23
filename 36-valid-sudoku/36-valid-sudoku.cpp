class Solution {
public:
    
    bool canPlace(vector<vector<char>>& board, int i, int j, char num){
        
        int idx ; 
        int occ = 0 ;
        
        for(idx = 0 ; idx <  9 ; idx++){
            
            //Row Check 
            if(board[i][idx] == num) occ++ ;
            if(board[idx][j] == num) occ++ ;
            if(board[(i/3)*3 + idx/3][(j/3)*3 + idx%3] == num) occ++ ;
            
        }
        
        if(occ > 3) return false ;
        
        return true ;
        
    }
    
   
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                
                if(board[i][j] != '.'){
                    char num = board[i][j] ;
                    
                    if(!canPlace(board,i,j,num))  
                        return false ;
                    
                   
                }
            }
        }
        
        return true  ;
    }
};