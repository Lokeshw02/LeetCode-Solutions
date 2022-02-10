class Solution {
public:
    
    int robHelper(vector<int>&nums,int startIdx, int endIdx,vector<int>&dp){

      
       if(startIdx>endIdx) return 0;
     
       if(dp[startIdx] != -1) return dp[startIdx];
      
       int  money1 = nums[startIdx]+robHelper(nums,startIdx+2,endIdx,dp);
       
       int money2 = robHelper(nums,startIdx+1,endIdx,dp);
      
       dp[startIdx] = max(money1,money2);
        return dp[startIdx];
   }
    
    
    
    int rob(vector<int>& nums) {
        
         int n = nums.size() ;
        if(n==1) return nums[0] ;
   
        
    vector<int>dp1(nums.size(),-1) ;
       
        
        int r1 = robHelper(nums,0,n-2,dp1) ;
        vector<int>dp2(nums.size(),-1) ;
        int r2 = robHelper(nums,1,n-1,dp2) ;
        
     return max(r1,r2);
        
    }
};