class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int k = n/4 ; 
        int ans = INT_MAX ;
        unordered_map<char,int> m ;
        
        for(char c: s){
            m[c]++ ;
        }
        
        int i = 0 ;
        for(int j = 0 ; j < n ; j++){
   
            m[s[j]]-- ;
            
            while(i < n && m['W'] <= k && m['Q'] <= k && m['E'] <= k && m['R'] <= k) 
            {
                ans = min(ans,j-i+1) ;
                m[s[i]]++ ;
                i++ ;
            }
        
        
        }
            return ans ;
    }
};