class Solution {
public:
   int solve(int n,int target,vector<vector<int>>&dp,vector<int>&nums){
        if(n==0){
            if(target==0 and nums[0]==0) return 2;
            if(target==0 or target==nums[0]) return 1;
            return 0;
        }
        if(dp[n][target]!=-1) return dp[n][target];
        int np = solve(n-1,target,dp,nums);
        int p =0;
        if(target>=nums[n]) p = solve(n-1,target-nums[n],dp,nums);
        return dp[n][target] = p+np;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum-target < 0 or (sum-target)%2) return 0;
        vector<vector<int>>dp(n+1,vector<int>((sum-target)/2 +1, -1));
        return solve(n-1,(sum-target)/2,dp,nums);
    }
};