class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp , int i){
        
        if(i >= nums.size() -1) 
            return 0 ;
        
        if(dp[i] != 10001)
            return dp[i] ;
        
        for(int j =1 ; j <= nums[i] ; j++){
            dp[i] = min(dp[i] ,1 + helper(nums,dp,i+j)) ;
        }
        
        return dp[i] ;
        
    }
    
    int jump(vector<int>& nums) {
        
        int n = nums.size() ;
        vector<int>dp(n,10001) ; 
        
        return helper(nums,dp,0) ;
        
        
    }
};