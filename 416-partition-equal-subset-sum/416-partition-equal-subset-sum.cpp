class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        long long int totalSum = 0;
        
        for(int x: nums){
         totalSum += x ;   
        }
        
        if(totalSum%2 == 1) return false ;
        else totalSum = totalSum/2 ;
        
        int N = nums.size(), sum = totalSum ;
        
         vector<vector<bool>>dp(N+1,vector<bool>(sum+1)) ;
             int i,j ;
        
        for(i=0;i<N+1;i++){
            for(j=0;j<sum+1;j++){
                
                if(i==0) dp[i][j] = false  ;
                if(j==0) dp[i][j] = true ;
                
            }
        }
        
         for(i=1;i<N+1;i++){
            for(j=1;j<sum+1;j++){
                
               if(nums[i-1]<= j ) dp[i][j]  = dp[i-1][j-nums[i-1]] || dp[i-1][j] ;
               else 
               dp[i][j] = dp[i-1][j] ;
                
            }
        }
        
        
        return dp[N][sum] ;
            
            
        
    }
};