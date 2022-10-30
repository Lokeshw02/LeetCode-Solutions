class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
         int n=nums.size();
        int mask=(1<<n),sum=0;
        vector<bool>dp(mask,false);
        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        if(sum%k!=0)
            return false;
        sum/=k;
        sort(nums.begin(),nums.end());
        if(nums[n-1]>sum)
            return false;
        vector<int>total(mask,0);
        dp[0]=true;
        for(int i=0;i<mask;i++)
        {
            if(dp[i])
            {
                for(int j=0;j<n;j++)
                {
                    int temp=i|(1<<j);
                    if(temp!=i)
                    {
                        if(nums[j]<=sum-(total[i]%sum))
                        {
                            dp[temp]=true;
                            total[temp]=nums[j]+total[i];
                        }
                        else
                            break;
                    }
                }
            }
        }
         return dp[mask-1];


        
    }
};