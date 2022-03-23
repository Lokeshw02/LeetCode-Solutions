class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size() ;
        
    int prev = nums[0] ;
    int curr ;
    
    int res = prev ;
    
    for(int i =1;i <n ;i++){
        curr = max(nums[i], prev + nums[i]) ;
        res = max(res, curr) ;
        
        prev = curr ;
    }
    
    
    return res ;
    }
};