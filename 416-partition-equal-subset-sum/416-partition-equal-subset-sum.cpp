class Solution {
public:
    
    int helper(vector<int>& nums, int sum, int n, vector<vector<int>>&dp){
        
        if(sum == 0 ) return true ;
        if(n == 0 ) return false ;
        
        
        if(dp[n][sum] != -1) return dp[n][sum] ;
        
        
        if(nums[n-1] <= sum) {
            
            return  dp[n][sum] = helper(nums, sum - nums[n-1], n-1,dp) || helper(nums, sum, n-1,dp) ;
        }
        else 
            return  dp[n][sum] = helper(nums, sum, n-1,dp) ;
        
     
    }
    
    
    
    
    
    
    
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size() ;
        int sum = 0 ;
      
        for(int x : nums) sum += x ;
        
        if(sum %2 == 1 ) return false ;
        
         vector<vector<int>>dp(n+1,vector<int>(sum/2 +1, -1)) ;
        
         
        int ans =  helper(nums, sum/2 ,n,dp) ;
        
        return ans == 1 ? true : false ;
           
        
    }
};