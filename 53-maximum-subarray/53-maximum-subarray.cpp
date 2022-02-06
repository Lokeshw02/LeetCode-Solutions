class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(),i,res,curr,prev ;
        
        prev = nums[0] ;
        res = prev ;
        
        for(i =1;i<n;i++){
            curr = max(nums[i], prev+nums[i]) ;
            res = max(res,curr) ;
            prev = curr ;
        }
         
           return res ; 
    }
};