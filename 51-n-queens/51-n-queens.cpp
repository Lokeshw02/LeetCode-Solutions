class Solution {
public:
    
    void helper(int n, int rowNum, vector<bool>&rowV,vector<bool>&colV,vector<bool>&pdV,vector<bool>&sdV, vector<string> &currboard,vector<vector<string>> &res){
        
        int col ;
        
        if(rowNum == n ){
            res.push_back(currboard) ;
            return ;
        }
        
        for(col = 0 ; col < n ; col++){
            if(rowV[rowNum] || colV[col] || pdV[rowNum - col + n -1 ] || sdV[rowNum + col] ) 
                continue  ;
            
            rowV[rowNum] = true ;
            colV[col] = true ;
            pdV[rowNum - col + n -1 ] = true ;
            sdV[rowNum + col] = true ;
            
            currboard[rowNum][col] = 'Q' ;
            
            helper(n,rowNum+1,rowV,colV,pdV,sdV,currboard,res) ;
            
            currboard[rowNum][col] = '.' ;
            
            sdV[rowNum + col] = false ;
            pdV[rowNum - col + n -1 ] = false ;
            colV[col] = false ;
            rowV[rowNum] = false ;
           
            
        }
        
        
    }
    
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<bool>rowV(n,false) ;
         vector<bool>colV(n,false) ; 
         vector<bool>pdV(2*n-1,false) ; 
         vector<bool>sdV(2*n-1,false) ;  
        
        vector<string> currboard(n,string(n,'.')) ;  
        vector<vector<string>> res ;
        
         helper(n,0,rowV,colV,pdV,sdV,currboard,res) ; 
        
        return res ;
    }
};