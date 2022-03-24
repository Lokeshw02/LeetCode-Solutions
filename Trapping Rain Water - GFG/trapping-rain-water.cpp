// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        
        int l = 0, r = n-1, lvalue = arr[0], rvalue = arr[n-1] ;
        long long  res = 0;
        
        
        while(l<r){
            
            if(lvalue<rvalue){
                int surplus = lvalue - arr[l] ;
                if(surplus){
                    res += surplus ;
                    
                }
                l++ ;
                lvalue = max(lvalue,arr[l]) ;
                
                
            }
            else{
                
                int surplus = rvalue - arr[r] ;
                if(surplus){
                    res += surplus ;
                    
                }
                 
                r-- ;
                rvalue = max(rvalue,arr[r]) ;
                 
                
            }
            
            
            
            
            
            
        }
        
        return res ;
        
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends