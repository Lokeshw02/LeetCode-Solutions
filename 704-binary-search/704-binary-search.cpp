class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0 , hi = nums.size()-1 , mid ;
        
        ////FFFF*TTTT*
        
        
        while(lo<hi){
            
            mid = lo + (hi-lo)/2 ;
                
            if(nums[mid]==target) return mid ;
            
            if(nums[mid]>=target)
                hi = mid ;
            else
                lo = mid+1 ;
            
            
            
        }
        
        if(nums[lo] != target) return -1 ;
        
        return lo ;
        
        
    }
};