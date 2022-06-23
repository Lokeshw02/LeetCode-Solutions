class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        
       int lo = 0 ;
       int hi = a.size() -1 ;
       
        int mid ;
        
        
        
        
        while(lo<hi){
            
            mid = lo + (hi-lo)/2 ;
                
                
            if(a[mid] - mid -1  < k )
                lo = mid+1 ;
                
            else 
                hi = mid ;
            
            
            
        }
        
             
            if(a[lo] - lo -1  < k )
                return k + lo + 1 ;
        
            return  k + lo ;
        
        
    }
};