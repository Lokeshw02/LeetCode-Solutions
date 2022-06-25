class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int lo = 0 ;
        int hi = nums.size() -1 ;
        
        int mid ;
        
        while(lo<hi){
            
            mid = lo + (hi-lo)/2 ;
            
            if(nums[mid+1] < nums[mid]) 
                hi = mid ;
            else 
                lo = mid +1 ;
            
             
            
        }
        
        return lo ;
    }
};