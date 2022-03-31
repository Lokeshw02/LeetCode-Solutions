// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:  
         
         void isSubset(int n ,vector<int>&arr, int sum,vector<vector<int>>&dp){
            
             
             
             int i,j ;
             
             for(i = 0; i<n+1;i++){
                 for(j = 0;j<sum+1;j++){
                     
                     if(i == 0) dp[i][j] = false ;
                     if(j==0) dp[i][j] = true ;
                     
                     
                 }
             }
             
             
             for(i = 1; i<n+1;i++){
                 for(j = 1;j<sum+1;j++){
                    
                    if(arr[i-1]<=j)
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j] ;
                    else
                    dp[i][j] = dp[i-1][j] ;
                      
                     
                 }
             }
             
             
        
             
         }  
  
  
  
  
  
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int range = 0 ;
	    
	    for( int x =0;x<n;x++)
	    range += arr[x] ;
	    
	    vector<int>arr1(arr,arr+n) ;
	    
	     
	     vector<vector<int>> dp( n+1 , vector<int> (range+1, 0));
	     
	     isSubset(n,arr1,range,dp) ;
	     
	     
	     
	     int mn = INT_MAX ;
	     
	     for(int i = 0;i<=range/2;i++){
	         
	         
	         if(dp[n][i])
	         
	         mn = min(mn,range - 2*i) ;
	         
	     }
	     
	    
	     
	     
	    return mn ;
	    
	    
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends