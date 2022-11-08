class Solution {
public:
    
    int dp[200][200][200] ={0} ;
    
    int helper(vector<int>& boxes, int l, int r , int k) {

    if(l>r ) 
        return 0 ;
        
    if(dp[l][r][k] > 0) return dp[l][r][k] ;
        
        int lrg = l, krg = k ;
        
       while(l+1 <= r && boxes[l] == boxes[l+1]){
           l++ ;
           k++ ;
       }
        
       int ans = (k+1)*(k+1) + helper(boxes,l+1,r,0) ;
        
       for(int m = l+1; m <= r ; m++){
           
           if(boxes[m] == boxes[l]) 
               ans = max(ans , helper(boxes,m,r,k+1) + helper(boxes,l+1,m-1,0)) ;
       }
        
        return dp[lrg][r][krg] = ans  ;

    }
     
    int removeBoxes(vector<int>& boxes) {
        return helper(boxes,0,boxes.size() -1 ,0) ;
    }
};