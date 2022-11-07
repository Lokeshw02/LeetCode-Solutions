class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
       int n = nums.size() ;
        
     //   vector<int>dp(n,0 ) ;
        
      //  dp[0] = nums[0] ;
        int prevsum = nums[0] ;
        int ans = nums[0] ;
        int  currsum = nums[0] ;
        
        for(int i = 1 ;  i < n ; i++){
            
             
            // dp[i] = max(dp[i-1] + nums[i] , nums[i]) ;
            currsum = max (nums[i], prevsum + nums[i] ) ; 
            ans = max (currsum, ans) ;
            prevsum = currsum ;
        }
        
        return ans ;
    }
};