class Solution {
public:
    
    int countLessthanOrEqualTo(vector<vector<int>>& matrix, int mid){
        int i = matrix.size() -1 ;
        int j = 0 ;
        int c = 0 ;
        
        while(i>=0 && j<matrix[0].size()){
            
            if(matrix[i][j] > mid){
                i-- ;
            }
            
            else{
                c += i+1 ;
                j++ ;
            }
        }
        
        return c ;
        
    }
    
 
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    
        
        int lo = matrix[0][0] ;
        int n =  matrix[0].size() ;
        int hi = matrix[n-1][n-1] ;
        int ans,mid ;
        
        while(lo<=hi){
            
            mid = lo + (hi-lo)/2 ;
            
            if(countLessthanOrEqualTo(matrix,mid) < k)
                lo = mid +1 ;
            
            else {
                ans = mid ;
                hi = mid -1 ;
            }
                
        }
        
        return ans ;
        
        
    }
};