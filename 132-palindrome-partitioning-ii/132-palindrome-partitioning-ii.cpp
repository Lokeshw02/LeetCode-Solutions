class Solution {
public:
    
    int dp[2005][2005];
    
    
    bool isPalindrome(string &s, int start, int end ){
        while(start<=end){
            if(s[start] != s[end])
                return false ;
            start++;end--;
            
        }
        return true ;
    }
   
    int solve(string s, int i, int j){
	if(i>=j) 
      return 0;
	if(dp[i][j]!=-1)
        return dp[i][j];
	if(isPalindrome(s,i,j)) 
        return 0;
	int mn = INT_MAX;
	for(int k=i;k<=j-1;k++){
		if(isPalindrome(s,i,k)) 
            mn = min(mn, 1+solve(s,k+1,j));
        dp[i][j] = mn;
	}
    
	return dp[i][j];
}

int minCut(string s) {
    int l=s.length();
    memset(dp,-1,sizeof(dp));
    
    int ans=solve(s,0,l-1);
    return ans;
    
}
    
    
   
};