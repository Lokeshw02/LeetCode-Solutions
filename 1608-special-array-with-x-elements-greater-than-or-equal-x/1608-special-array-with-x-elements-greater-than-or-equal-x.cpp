class Solution {
public:
    
    int BS(vector<int> & nums, int s){
        
        int lo = 0 ;
        int hi = nums.size() ;
        
        int mid ;
        
        while(lo<hi){
            
            mid =  lo + (hi-lo)/2 ;
                
            if(nums[mid] >= s) 
                
                hi = mid ;
                
            else 
                lo = mid +1 ;
                
            
    
        }
        
        return nums.size() - lo  ;
        
        
        
    }
    
 
    
    int specialArray(vector<int>& nums) {
        
        sort(nums.begin(),nums.end()) ;
        
        for(int c = 0 ; c <= nums.size(); c++){
            
            int r = BS(nums,c) ;
            
            if(r == c) 
                return c ;
            
            
            
            
        }
        
        return -1 ;
        
        
    }
};