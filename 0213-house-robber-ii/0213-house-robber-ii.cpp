class Solution {
public:
    
    
    int helper1(int i, vector<int>&nums, vector<int>&dp){
        int n = nums.size() ;
        
        if(i >= n-1)
            return 0 ;
        //Include 
        
        if(dp[i] != -1) 
            return dp[i] ;
        
        int amount1 = nums[i] + helper1(i+2,nums,dp) ;
        //Not include 
        int amount2 = helper1(i+1,nums,dp) ;
        
        return dp[i] = max(amount1,amount2) ;
    }
    
    int helper2(int i, vector<int>&nums, vector<int>&dp){
        int n = nums.size() ;
        
        if(i >= n)
            return 0 ;
        
        if(dp[i] != -1) 
            return dp[i] ;
        //Include 
        
        int amount1 = nums[i] + helper2(i+2,nums,dp) ;
        //Not include 
        int amount2 = helper2(i+1,nums,dp) ;
        
        return dp[i] = max(amount1,amount2) ;
    }
    
    
    int rob(vector<int>& nums) {
        
        int n = nums.size() ;
        
        if(n== 1) 
            return nums[0] ;
        
         vector<int> dp1(n,-1) ;
          vector<int> dp2(n,-1) ;
        
        
        // 0 to n-2
        
        int res1 = helper1(0,nums,dp1) ;
        
       
      
        //1 to n-1  
         int res2 = helper2(1,nums,dp2) ; 
        
       return max(res1,res2) ;
        
        
    }
};