class Solution {
public:
    
    
    int helper(vector<int>&nums,int i,int prev, bool lastUp, vector<vector<int>>&dp){
        int n = nums.size() ;
        
        if(i>=n) return 0 ;
        
        if(dp[i][lastUp] != -1) return dp[i][lastUp] ;
        
        if(nums[i]>prev && !lastUp) return dp[i][lastUp] = 1 + helper(nums,i+1,nums[i],true,dp) ;
        
        if(nums[i]<prev && lastUp) return dp[i][lastUp] = 1 + helper(nums,i+1,nums[i],false,dp) ;
        
        return dp[i][lastUp] = helper(nums,i+1,nums[i],lastUp,dp) ; 
        
    }
    
    
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(2,-1)) ;
        
        int longestInc = 1+helper(nums,0,nums[0],false,dp);
        int longestDec = 1+helper(nums,0,nums[0],true,dp);
        
        return max(longestInc, longestDec);
    }
};