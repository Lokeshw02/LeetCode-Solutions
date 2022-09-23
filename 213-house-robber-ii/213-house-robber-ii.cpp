class Solution {
public:
    
    int helper1(vector<int>& nums,vector<int>&dp, int i){
        
        if(i >= nums.size() -1 )
            return 0 ;
        
        if(dp[i] != -1) 
            return dp[i] ;
        
        //Include 
        int amount1 = nums[i] + helper1(nums,dp,i+2) ;
        
        int amount2 = helper1(nums,dp,i+1) ;
        
        return dp[i] = max(amount1,amount2) ;
        
        
    }
    
     int helper2(vector<int>& nums,vector<int>&dp, int i){
        
        if(i >= nums.size()  )
            return 0 ;
        
        if(dp[i] != -1) 
            return dp[i] ;
        
        //Include 
        int amount1 = nums[i] + helper2(nums,dp,i+2) ;
        
        int amount2 = helper2(nums,dp,i+1) ;
        
        return dp[i] = max(amount1,amount2) ;
        
        
    }
    
    
    int rob(vector<int>& nums) {
        //0 t0 n-2 
        //1 to n-1  
        
        int n = nums.size() ;
        
        if(n == 1) return nums[0] ;
        
        vector<int>dp1(n,-1) ; 
        vector<int>dp2(n,-1) ; 
        
        return max(helper1(nums,dp1,0), helper2(nums,dp2,1)) ;
        
        
        
    }
};