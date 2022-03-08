class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        
        if (nums[nums.size() -1] < target) return nums.size() ;
        
       
        
        int lo = 0, hi = nums.size() -1 , mid  ;
        
        while(lo<hi) {
            
            
            mid = lo + (hi-lo)/2 ;
            
            if(nums[mid] >= target) {
                
                hi = mid ;
                
                
                
            }
            
            else {
                lo = mid + 1  ;
                
            }
            
        }
        
        return lo ;
        
        
        
    }
};