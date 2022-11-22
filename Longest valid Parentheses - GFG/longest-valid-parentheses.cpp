//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string s){
        // code here
       int n = s.size() ,i , res = 0 , L ;
        
        if(n==0) return 0 ;
        
        vector<int> dp (n, 0) ;
        
        dp[0] = 0 ;
        
        for(i = 1; i< n;i++){
            
               
               if(s[i] == ')'){
               
                
                if(i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '('){
                   
               
                    
                    dp[i] = 2 + dp[i-1] ;
                    
                    if(i-dp[i-1]-2 >= 0) 
                        dp[i] += dp[i-dp[i-1]-2] ;
                }
            }
            
            res = max(res,dp[i]) ;
            
        }
        
        return res ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends