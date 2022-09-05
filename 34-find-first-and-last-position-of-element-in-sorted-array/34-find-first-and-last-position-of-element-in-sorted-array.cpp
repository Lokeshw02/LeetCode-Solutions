class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lo = 0 ;
        int hi = nums.size() -1 ;
        int mid ;
        int p1,p2 ;
        //FIrst Postion 
        while(lo <= hi){
            
            mid = lo + (hi-lo)/2 ;
            
            if(nums[mid] > target )
                hi = mid -1 ;
            else if(nums[mid] < target )
                lo = mid +1 ;
            else {
                
                if(mid == 0){
                    p1 = mid ;
                    break ;
                } 
                
                if(nums[mid-1] != target )
                    { p1 = mid ;
                    break ;}
                else 
                    hi = mid -1 ;
            }
                
        }
        
        if(lo>hi) return {-1,-1} ;
        
        else p1 = mid ;
        
        //Last Occurance 
        
        lo = 0, hi = nums.size() -1 ;
        
        while(lo <= hi){
            
            mid = lo + (hi-lo)/2 ;
            
            if(nums[mid] > target )
                hi = mid -1 ;
            else if(nums[mid] < target )
                lo = mid +1 ;
            else {
                
                if(mid == nums.size() -1) {
                    p2 = mid ;
                    break ;
                }
                
                if(nums[mid+1] != target )
                   { p2 = mid ;
                    break ;}
                else 
                    lo  = mid + 1 ;
            }
                
        }
        
        
        
        return {p1,p2} ;
        
        
    }
};