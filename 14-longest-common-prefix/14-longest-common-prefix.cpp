class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string res = "" ;
     
        sort(strs.begin(), strs.end(),[](string &a, string &b){
            return a.size() < b.size() ;
        }) ;
        
        bool flag = true, tflag ;
        
       for(int i = 0; i < strs[0].size() ; i++){
           
           char t = strs[0][i] ;
           
           for(int j = 1; j < strs.size() ; j++){
              
               
              if(strs[j][i] == t) tflag = true ;
              
               else tflag = false ;
                    
              flag = flag && tflag ;    
           }
           
           if(flag)
               res += t ;
       }
        
        return res ;
    }
};