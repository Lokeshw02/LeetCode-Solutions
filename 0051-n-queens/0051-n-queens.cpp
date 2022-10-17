class Solution {
public:
    
    void helper(int row, int n,vector<bool>&rowV,vector<bool>&colV,vector<bool>&pdV,vector<bool>&sdV, vector<string>&currBoard,vector<vector<string>>&res ){
        
        int col ;
        
        if(row == n){
            res.push_back(currBoard) ;
            return ;
        }
        
        for(col = 0; col < n; col++){
            
            if(rowV[row] || colV[col] || pdV[row+col] || sdV[row-col+n-1])
                continue ;
            
                rowV[row] = true ;
                colV[col] = true ;
                pdV[row+col] = true ;
                sdV[row-col+n-1] = true ;
            
            
                currBoard[row][col] = 'Q' ; 
                
                helper(row +1 , n, rowV,colV, pdV, sdV,currBoard,res) ;
                    
                currBoard[row][col] = '.' ;
                    
                rowV[row] = false ;
                colV[col] = false ;
                pdV[row+col] = false ;
                sdV[row-col+n-1] = false ;
                    
        }
    }
                
            
                  
            
    
    
    
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<bool>rowV(n,false) ;
        vector<bool>colV(n,false) ;
        vector<bool>pdV(2*n-1,false) ;
        vector<bool>sdV(2*n-1,false) ;
        
        vector<string>currBoard(n,string(n,'.')) ;
        vector<vector<string>>res ;
        
         helper(0,n,rowV,colV,pdV,sdV,currBoard,res) ;
        
        return res ;
        
        
    }
};