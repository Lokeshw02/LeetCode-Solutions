class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size() ;
        
       int prev = nums[0] ;
       int res = prev ;
       int curr;
        
        
        for(int i = 1; i<n; i++){
         
        curr = max(nums[i],nums[i]+prev) ;
        res = max(res,curr) ;
        
        prev = curr ;
        }
        
        return res ;
    }
};