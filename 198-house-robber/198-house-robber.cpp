class Solution {
public:
    
    
    int helper(vector<int>& nums,vector<int>&dp, int i){
        
        if(i >= nums.size())
            return 0 ;
        
        if(dp[i] != -1) 
            return dp[i] ;
        
        //Include 
        int amount1 = nums[i] + helper(nums,dp,i+2) ;
        
        int amount2 = helper(nums,dp,i+1) ;
        
        return dp[i] = max(amount1,amount2) ;
        
        
    }
    
   
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        
        vector<int>dp(n,-1) ;
        //0 to n-1  
        
        return helper(nums,dp,0) ;
        
        
        
        
    }
};