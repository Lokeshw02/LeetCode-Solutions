class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0 , hi = nums.size() - 1 , n = nums.size(), mid  ;
        
        if(n == 1 ) return 0 ;
        
        while(lo <= hi){
            
            mid = lo + (hi-lo)/2 ;
            
            
            if(mid == n-1) {
                if(nums[mid] >= nums[mid-1]) 
                    return mid ;
                else 
                    {hi = mid -1 ;
                    continue ;}
            }
            
            if(mid == 0){
               if(nums[mid] > nums[mid+1]) 
                   return mid;
                else
                    {lo = mid +1 ;
                    continue ;}
                   
            }
            
            
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) 
                return mid ;
             else if(nums[mid+1] > nums[mid])
                lo = mid  + 1 ; 
            else if(nums[mid-1] > nums[mid])
                hi = mid -1 ;
            
            
        }
      
    
    
        return mid ;
    
    
    
    }
};