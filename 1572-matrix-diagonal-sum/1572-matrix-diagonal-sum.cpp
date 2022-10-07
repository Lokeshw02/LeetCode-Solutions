class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int  n = mat.size() ;
        
        vector<vector<bool>>visited(n,vector<bool>(n,false)) ;
        
        int i =0 , j= 0 , sum = 0 ;
        
        while(i<n && j <n){
            
            if(!visited[i][j])
           { sum += mat[i][j] ;
            visited[i][j] = true ;}
            
            i++ ;j++ ;
            
        }
        
        i = 0, j = n-1 ; 
        
         while(i<n && j >= 0){
            
            if(!visited[i][j])
           { sum += mat[i][j] ;
            visited[i][j] = true ;}
            
            i++ ;j-- ;
            
        }
        
        return sum ;
        
    }
};