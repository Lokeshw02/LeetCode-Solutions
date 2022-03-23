// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    
	    int count = 0 ;
	    
	   sort(arr,arr+n) ;
	   
	  
	   
	   
	   
	   for(int i = n-1; i>=0 ; i--){
	       
	        int lo = 0, hi = n-1 ;
	       
	       while(lo<hi){
	             
	       if(arr[lo]+arr[hi] == arr[i] ){
	           count ++ ;
	           hi = hi-1 ;
	           lo = lo+1 ;
	       }
	       else if(arr[lo]+arr[hi] < arr[i])
	       lo++ ;
	       else 
	       hi-- ;
	       
	       
	       
	       
	   }
	       
	       
	   }
	   
	 
	    return count ;
	}
	
};

// { Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // } Driver Code Ends