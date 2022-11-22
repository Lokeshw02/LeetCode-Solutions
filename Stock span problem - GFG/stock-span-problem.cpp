//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int nums[], int n)
    {
       // Your code here
       
       stack<pair<int,int>> stk ;
       vector<int> res ;
       
       for(int i = 0 ; i < n ; i++){
           
           if(stk.empty()) 
           res.push_back(-1) ;
           
           else if(!stk.empty() && stk.top().first > nums[i] ) 
           res.push_back(stk.top().second) ;
           
           else if(!stk.empty() && stk.top().first <=  nums[i]) 
           {
               while(!stk.empty() && stk.top().first <= nums[i]) 
               stk.pop() ;
               
               if(stk.empty()) 
               res.push_back(-1) ;
               else
               res.push_back(stk.top().second ) ;
           }
           
           stk.push({nums[i],i}) ;
       }
       
       for(int i = 0; i < res.size() ; i++){
           
           res[i] =  i - res[i] ;
       }
       
       return res ;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends