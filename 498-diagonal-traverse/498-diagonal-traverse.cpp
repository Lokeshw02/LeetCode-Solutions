class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        //If matrxi is empty 
        if(mat.size() == 0 || mat[0].size() == 0) return {} ;
        int m = mat.size(), n = mat[0].size() ;
        vector<int> res(m*n) ;
        int i = 0 ;
        int row = 0, col = 0 ;
        bool up = true ; 
        
        while(row < m && col < n ){
            //If diagobal is going up 
            if(up){
                while(row>0 && col < n-1){
                    res[i++] = mat[row][col] ;
                    row--;
                    col++ ;
                }
                res[i++] = mat[row][col] ;
                if(col == n-1){
                    row++ ;
                }
                else{
                    col++ ;
                }
            }
              //If diagonal is going down 
            else {
                
                while(col>0 && row < m-1){
                    res[i++] = mat[row][col] ;
                    row++;col-- ;
                }
                res[i++] = mat[row][col] ;
                if(row == m-1){
                    col++ ;
                }
                else{
                    row++ ;
                }
            }
            
            
            
           up = !up ;   
          
        }
        
        return res ;
      
    }
};