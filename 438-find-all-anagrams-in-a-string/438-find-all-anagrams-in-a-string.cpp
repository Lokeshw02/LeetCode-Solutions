class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>res ;
        vector<int>freq(26,0), window(26,0) ;
        int n = s.size(), m = p.size() ;
        int dist ;
        
        for(int i = 0 ; i < m; i++){
            freq[p[i] -'a']++ ;
        }
        
        for(int i = 0; i <= n-m ; i++){ 
            
            fill(window.begin(),window.end(), 0) ; 
           
            
            for(int j = i ; j < i+ m && j < n ; j++){ 
                
               
                     
                     window[s[j]-'a']++ ; 
                     
                    
                }
                
               
              if(window == freq ) 
                  res.push_back(i) ;
                
            
        }
        return res ;
    }
};