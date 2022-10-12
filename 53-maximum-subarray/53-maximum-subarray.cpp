class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
       int n = nums.size() ;
     
       int prev = nums[0], curr, res = nums[0] ; 
        
        for(int i =1 ; i < n ; i++){
        
            curr = max(nums[i],prev+nums[i]) ;
            res = max(res,curr) ;
            prev = curr ;
            
        }
        
        return res ;
    }
};