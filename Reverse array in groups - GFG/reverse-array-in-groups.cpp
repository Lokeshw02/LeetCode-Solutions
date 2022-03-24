// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    
    
       void f(vector<long long>& arr, int lo, int hi){
           
           while(lo<=hi){
               swap(arr[lo],arr[hi]) ;
               lo++; hi-- ;
           }
           
           
       }
    
    
    
    void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here
       int i = 0,j = k ;
       
       while(j<n){
           
           f(arr,i,j-1) ;
           i = j ;
           j = j+k ;
           
       }
       
       if(i != n-1)
       f(arr,i,n-1) ;
       
    }
};

// { Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
}

  // } Driver Code Ends