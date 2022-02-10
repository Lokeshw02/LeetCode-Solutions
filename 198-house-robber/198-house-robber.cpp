class Solution {
public:
   int robHelper(vector<int>&nums,int startIdx,vector<int>&dp){
       int n = nums.size();
      
       if(startIdx>=n) return 0;
     
       if(dp[startIdx] != -1) return dp[startIdx];
      
       int  money1 = nums[startIdx]+robHelper(nums,startIdx+2,dp);
       
       int money2 = robHelper(nums,startIdx+1,dp);
      
       dp[startIdx] = max(money1,money2);
        return dp[startIdx];
   }
   int rob(vector<int>& nums) {
    int n = nums.size();
       vector<int>dp(n,-1);
       return robHelper(nums,0,dp);
   }
};



