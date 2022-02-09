class Solution {
public:
    
    void helper(vector<bool>&colV,vector<bool>&rowV,vector<bool>&pdV,vector<bool>&sdV,int n,int rowNum,vector<string>& currBoard,vector<vector<string>>&res ){
        
        if(rowNum == n ) {
            res.push_back(currBoard) ;
            return ;
        }
        
        int col ;
        
        for(col =0; col<n;col++){
            if(rowV[rowNum]||colV[col]||pdV[rowNum-col+n-1]||sdV[rowNum+col])
                continue ;
            
            rowV[rowNum] = true;
            colV[col]= true;
            pdV[rowNum-col+n-1]= true;
            sdV[rowNum+col]= true;
            
            currBoard[rowNum][col] = 'Q' ;
            
            helper(colV,rowV,pdV,sdV,n,rowNum+1,currBoard,res) ;
            
            currBoard[rowNum][col] = '.' ;
            
             sdV[rowNum+col]= false;
             pdV[rowNum-col+n-1]= false;
             colV[col]= false;
             rowV[rowNum] = false;
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<bool>colV(n,false) ;
        vector<bool>rowV(n,false) ;
        vector<bool>pdV(2*n -1,false) ;
        vector<bool>sdV(2*n -1,false) ;
        vector<string>currBoard(n,string(n,'.')) ;
        vector<vector<string>> res ;
        
         helper(colV,rowV,pdV,sdV,n,0,currBoard,res) ;
             
        
        return res ;
    }
};