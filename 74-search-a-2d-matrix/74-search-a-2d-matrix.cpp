class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
         
        int m= matrix.size(),i,j;
        int n = matrix[0].size(),lo,hi,mid;
        
        if(n==0) return false;
        if (matrix.size() == 0) return false;
        
        lo= 0, hi = m*n -1;
        
        while(lo<hi)
        {
            mid = lo+(hi-lo)/2;
                
            i = mid/n;
            j = mid%n;
            
        if(matrix[i][j] >= target)
            hi = mid;
        else
         lo = mid+1;
           }
        //Sanity Chek
        
       i = lo/n;
       j = lo%n;
        
        return(matrix[i][j] == target?true : false);
        
    }
};