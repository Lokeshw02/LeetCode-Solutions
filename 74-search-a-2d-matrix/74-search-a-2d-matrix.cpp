class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
       if( matrix.size() == 0 || matrix[0].size() ==0) return false ;
        
         
       int n = matrix.size() ;
       int m = matrix[0].size() ;
        

       
       int lo = 0 ;
       int hi = m*n -1 ;
       int mid,i,j ;
    
        
        while(lo<hi){
            
            mid = lo + (hi-lo)/2 ;
            
            i = mid/m ;
            j = mid%m ;
            
            if(matrix[i][j] >= target)
                hi = mid ;
            else 
                lo = mid +1 ;
                 
            
        }
        
        i = lo/m ;
        j = lo%m ;
        
      return   matrix[i][j] == target ? true : false ;
       
        
    }
};