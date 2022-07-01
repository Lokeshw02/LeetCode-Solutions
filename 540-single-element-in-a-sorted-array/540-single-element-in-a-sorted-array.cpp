class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       
        
        if(nums.size() == 1) 
            return nums[0] ;
        
        int lo = 0 ;
        int hi = nums.size() -1 ;
        
        int mid ;
        
        while(lo<=hi){
            
            mid = lo + (hi-lo)/2 ;
            
            //If mid is Odd -> If sequence is good till here, the element at Index mid -1 will be same as that on mid  OR  If mid is Even and sequence till here is good, then the element mist be equal to element at Index mid +1 ; 
            
            
            
            
            if (mid % 2 == 1 && nums[mid] == nums[mid-1] || mid % 2 == 0 && nums[mid] == nums[mid+1] )
                lo = mid +  1 ;
            else 
                hi = mid -1 ;
 
                
        }
        
        return nums[lo] ;
    }
};