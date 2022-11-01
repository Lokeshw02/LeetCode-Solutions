class Solution {
public:
    int dp[500005];
    int helper(vector<int>&arr, int start, int n){
        
        if(start >= n || start < 0 ) 
            return 0 ;
        
        if(arr[start] == 0)
            return 1;
        
        if(dp[start]!= -1 )
            return dp[start] ;
         dp[start] = 0;
       
        int res = helper(arr,start + arr[start],n) || helper(arr,start-arr[start],n);
        dp[start] = res;
        return res;
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size() ;
        memset(dp,-1,sizeof(dp));
        return helper(arr,start,n);
    }
};