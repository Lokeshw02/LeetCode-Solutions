class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        
        
         int total_sum = 0 ;
        int n = arr.size() ;
    for(int i = 0; i<n ; i++){total_sum += arr[i] ;} 
        
   
    
    
    if( (target+ total_sum)%2 ) return 0 ;
        
         
        
         
    int req  = (target+ total_sum)/2 ;
        
    if(req<0)
        return 0;
        
        int dp[n+1][req+1];
    
    for(int i = 0 ; i < n+1 ; i++){
        for(int j = 0; j< req +1 ; j++){
            if(i == 0) dp[i][j]= 0 ;
            if(j == 0) dp[i][j] = 1 ;
            
        }
    }
    
     for(int i = 1 ; i < n+1 ; i++){
        for(int j = 0; j< req +1 ; j++){
           
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]] ;
            
            else 
                dp[i][j] = dp[i-1][j]  ;
          
        }
    }
    return dp[n][req] ;
    }
};