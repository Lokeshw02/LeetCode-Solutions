class Solution {
public:
    
     int maxsum ;
   
    int helper(vector<int>& nums, vector<int>&dp, int n)
	{
		if (dp[n]!=INT_MAX)
			return dp[n];
		if (n == 0)
			dp[n] = nums[0];
		else
		{
			int d1 = helper(nums, dp, n - 1) + nums[n];
			if (d1 > nums[n])
			{
				dp[n] = d1;
			}
			else
			{
				dp[n] = nums[n];
			}
		}
		
        if (dp[n] > maxsum)
			maxsum = dp[n];
        
		return dp[n];
	}

    
       
    int maxSubArray(vector<int>& nums) {
        maxsum = INT_MIN;
		vector<int>dp(nums.size(),INT_MAX) ;
        
		
		helper(nums, dp, nums.size() - 1);
		return maxsum;
    }
};