class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int lo = 0 ;
        int hi = nums.size() -1 , n = nums.size() ;
        int mid, pivot  ;
        
//         if( n == 1 ){
            
//             if(nums[0] == target ) 
//                 return 0 ;
            
//             return -1 ;
//         }
        
        while(lo <= hi){
            
            mid = lo  + (hi-lo)/2 ;
            
           if(nums[mid] <= nums[n-1]) 
               hi = mid -1 ;
            
            else{
                if(nums[mid] > nums[mid+1] ) 
                {
                    pivot = mid ;
                    break ;
                }
                
                else 
                    lo = mid + 1 ;
            }
        }
            
            if(nums[0] <= target && target <= nums[pivot] ) 
            {
                lo = 0;
                hi = pivot ;
            }
            else 
            {
                lo = pivot +1 ;
                hi = n-1 ;
            }
        
        while(lo <= hi ){
            
            mid = lo + (hi-lo)/2 ;
            
            if(nums[mid] == target ) 
                return mid ;
            else if(nums[mid] > target )
                hi = mid -1 ;
            else 
                lo = mid +1 ;
        }
        
        return -1 ;
        
    }
};