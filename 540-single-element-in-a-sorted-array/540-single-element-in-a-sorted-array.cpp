class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0 ;
        int hi = nums.size() -1 ;
        int mid ;
        
       if(nums.size() == 1) return nums[0] ;
        
        while(lo <= hi){
            
            mid = lo + (hi-lo)/2 ;
      
          //Till here if seq, is good 
            if(mid%2 == 0 && nums[mid] == nums[mid+1] || mid%2 == 1 && nums[mid] == nums[mid-1]  )
                lo = mid +1 ;
            else 
                hi = mid -1 ;
      
        }
          return nums[lo] ;
    }
};