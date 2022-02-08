class Solution {
public:
    
    bool isPalindrome(string &s,int start,int end){
       
        while(start <= end){
            if(s[start] != s[end])
                return false ;
            start++ ;end-- ;
        }
        
        return true ;
    }
    
    void helper(string &s, int startIdx, vector<string>&currSet, vector<vector<string>>&res){
        int i, n = s.size() ;
        
         if(startIdx == n ){
            res.push_back(currSet) ;
            return ;
             }
       
        
        string prefix = "" ;
        
        for(i=startIdx;i<n;i++){
            
            prefix += s[i] ;
            
            if(!isPalindrome(prefix,0,prefix.size()-1))
                continue ;
            //
            
            currSet.push_back(prefix) ;
            
            helper(s,i+1,currSet,res) ;
            
            currSet.pop_back() ;
                        
        }
        
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<string>currSet ;
        vector<vector<string>> res ;
        helper(s,0,currSet,res) ;
        
       
        return res  ;
    }
};