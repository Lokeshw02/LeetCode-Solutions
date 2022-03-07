class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
  
        int n = nums.size() ;
        int lo = 0, hi = n-1, mid, firstPos, endPos ;
        
            if (n==0) return {-1,-1}  ;
        
        while(lo<hi){
            
            mid = lo+ (hi-lo)/2 ;
                
             if(nums[mid]>=target)
                 hi = mid ;
             else
                 lo = mid +1 ;
                  
                 
            
        }
        
       if(nums[lo] != target) {
           firstPos = -1 ;
       }
        else {
            firstPos = lo ;
        }
        
        
         lo = 0, hi = n-1;
         while(lo<hi){
            
            mid = lo+ (hi-lo+1)/2 ;
                
             if(nums[mid]>target)
                 hi = mid-1 ;
             else
                 lo = mid ;
                  
                 
            
        }
        
        if(nums[lo] != target) {
           endPos = -1 ;
       }
        else {
            endPos = lo ;
        }
        
        
        return {firstPos,endPos} ;
        
    }
};