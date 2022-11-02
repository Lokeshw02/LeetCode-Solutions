class Solution {
public:
    
   
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>text1 = nums1, text2 = nums2 ;
        int ans = 0 ;
        
          int m = text1.size(),  n = text2.size() ;
        vector<vector<int>>dp(m+1, vector<int>(n+1,0)) ; 
        
      
        
        for(int i =0 ; i < m+1 ; i++){
            for(int j = 0; j < n+1 ; j++){
               
                if(i == 0 || j == 0) 
                    dp[i][j] = 0 ;
            }
        }
        
        for(int i =1 ; i < m+1 ; i++){
            for(int j = 1; j < n+1 ; j++){
               
                if(nums1[i-1] == nums2[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1] ;
                else
                    dp[i][j] = 0 ;
                
                ans = max(ans, dp[i][j]) ;
            }
        }
        
                
        return ans ;
        
    }
};