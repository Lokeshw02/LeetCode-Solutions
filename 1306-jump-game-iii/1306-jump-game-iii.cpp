class Solution {
public:
     int dp[100005];
    int  solve(vector<int>&a,int idx,int n)
    {
        if(idx >= n || idx < 0)
            return 0;
        if(a[idx] == 0)
            return 1;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        dp[idx] = 0;
        
        int res = solve(a,idx+a[idx],n) || solve(a,idx-a[idx],n);
        
         dp[idx] = res;
        return res;
    }
    
//     int helper(vector<int> arr, vector<int> dp, int start, int n){
        
//         if(start >= n || start < 0 ) 
//             return 0 ;
        
//         if(dp[start] != -1 )
//             return dp[start] ;
        
//         if(arr[start] ==  0)
//             return dp[start] = 1;
        
//         int k = arr[start] ;
        
//        if(helper(arr,dp,start + k, n) || helper(arr,dp,start- k, n)) 
//                 return dp[start] = 1 ;
      
//       return dp[start] = 0;
        
//     }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size() ;
        memset(dp,-1,sizeof(dp));
        return solve(arr,start,n);
    }
};