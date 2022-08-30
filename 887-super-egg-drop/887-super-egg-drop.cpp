class Solution {
public:
    
    int dp[101][10001];
 //Taking up the Constraints
   int solve(int eggs,int floors){
        if(floors==0 || floors==1) return dp[eggs][floors]=floors;
    //Base condition 
        else if(eggs==1) return dp[eggs][floors]=floors;
    //Base condition
        else if(dp[eggs][floors]!=-1) return dp[eggs][floors];
   
        else{
   //Using Binary Search
          int l=1,h=floors;
          int mn=INT_MAX;
          while(l<=h) {
              int mid=l+(h-l)/2;
              int a=solve(eggs-1,mid-1);
              int b=solve(eggs,floors-mid);
              int x=max(a,b) + 1;
              mn=min(mn,x);
              if(a>b) h=mid-1;
              else l=mid+1;
          }
         dp[eggs][floors]=mn;   
        }  
        return dp[eggs][floors];
    } 
    
    
    int superEggDrop(int k, int n) {
        
        memset(dp,-1,sizeof(dp)); 
        //Initializing -1.
       return solve(k,n) ;
        
    }
};