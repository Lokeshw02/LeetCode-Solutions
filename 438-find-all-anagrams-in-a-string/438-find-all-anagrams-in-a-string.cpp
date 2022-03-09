class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int s_l = s.size() ;
        int p_l = p.size() ;
        
        if(s_l < p_l) return {} ;
        
        vector<int>freq_p(26,0) ;
        vector<int> window(26,0);
        
        for(int i =0; i< p_l; i++){
             freq_p[p[i]-'a']++;
              window[s[i]-'a']++;
        }
        
        vector<int>ans ;
        if(freq_p == window) ans.push_back(0);
        
        int j ;
        
        for( j =p_l; j<s_l ;j++){
            
               window[s[j-p_l] - 'a']--;
                window[s[j] - 'a']++;
            
            if(freq_p == window) ans.push_back(j-p_l+1);
        }
        
        
        
        return ans ;
            
        }
            
};