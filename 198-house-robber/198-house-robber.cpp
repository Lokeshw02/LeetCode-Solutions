class Solution {
public:
    
    int robhelper(vector<int>&nums,vector<int>&dp,int startIdx){
        
        
        
        
        if(startIdx >= nums.size())
            return 0 ;
        
        
        if(dp[startIdx] != -1) return dp[startIdx] ;
        
        
        //Thief starts from the startIdx house 
        
       int  m1 = nums[startIdx]+ robhelper(nums,dp,startIdx+2) ;
            
        // If it does not include startIdx
        
       int  m2 = robhelper(nums,dp,startIdx+1);
        
            
        dp[startIdx] = max(m1,m2) ;
        
        return dp[startIdx] ;
        
        
        
    }
      
    
    
    int rob(vector<int>& nums) {
        
        vector<int>dp(nums.size(),-1) ;
        
        return robhelper(nums,dp,0) ;
        
        
    }
};