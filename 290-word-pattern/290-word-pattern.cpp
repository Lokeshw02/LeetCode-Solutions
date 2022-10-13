class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string>v ;
        
        stringstream ss(s) ;
        string t ;
        
        while(getline(ss,t,' ')){
            v.push_back(t) ;
        }
        
        if(pattern.size() != v.size() ) return false ;
        
        unordered_map<char,string>mp1 ;
        unordered_map<string,char>mp2 ;
        
        
        for(int i = 0 ; i< pattern.size() ;i++){
            
            if(mp1.count(pattern[i])){
                 if( mp1[pattern[i]]  != v[i])
                     return false ;
            }
            
             if(mp2.count(v[i])){
                 if( mp2[v[i]]  != pattern[i])
                     return false ;
            }
            
            mp1[pattern[i]] = v[i] ;
            mp2[v[i]] =  pattern[i] ;
            
        }
        
        return true ;
    
        
    }
};
