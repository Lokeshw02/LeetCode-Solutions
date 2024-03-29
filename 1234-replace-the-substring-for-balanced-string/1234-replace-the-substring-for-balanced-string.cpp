class Solution {
public:
    int balancedString(string s) {
       
        int n = s.size() ;
        int k = n/4 ;
        
        int ans = INT_MAX ;
        int i = 0 ;
        
        unordered_map<char, int> m ;
        
        for(char c : s)
            m[c]++ ;
        
        for(int j = 0; j < n ; j++){
            
            m[s[j]]-- ;
            
            while(i < n && m['Q'] <= k && m['W'] <= k && m['E'] <= k && m['R'] <= k){
                ans = min(ans, j-i+1) ;
                m[s[i]]++ ;
                i++ ;
            }
        }
        
        return ans ;
    }
};