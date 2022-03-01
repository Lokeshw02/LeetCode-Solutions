class Solution {
public:
    int wiggleMaxLength(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        vector<int> dp(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] % 2 == 0){
                    if(arr[j] > arr[i]) dp[i] = max(dp[i],1 + dp[j]);
                }else{
                    if(arr[j] < arr[i]) dp[i] = max(dp[i],1 + dp[j]);
                }
            }
            ans = max(ans,dp[i]);
        }
        
        for(auto &it : dp) it = 1; // resetting the array so we can reuse it
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] % 2 == 0){
                    if(arr[j] < arr[i]) dp[i] = max(dp[i],1 + dp[j]);
                }else{
                    if(arr[j] > arr[i]) dp[i] = max(dp[i],1 + dp[j]);
                }
            }
            ans = max(ans,dp[i]);
        }        
        
        return ans;
    }
};