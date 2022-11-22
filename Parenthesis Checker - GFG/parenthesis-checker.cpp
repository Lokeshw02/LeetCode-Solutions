//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        
         stack<char> stk ;
        
        for(int i = 0; i < s.size() ; i++){
            
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') 
                stk.push(s[i]) ;
            else
            {
                if(stk.empty()) 
                    return false ;
                
                if(s[i] == ')' && stk.top() != '(') 
                    return false ;
                if(s[i] == ']' && stk.top() != '[') 
                    return false ;
                if(s[i] == '}' && stk.top() != '{') 
                    return false ;
                stk.pop() ;
                    
            }
            
            
        }
        
        if(stk.empty()) 
            return true ;
        
        return false ;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends