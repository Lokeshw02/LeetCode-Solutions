class Solution {
public:
    bool isValid(string s) {
        stack<char> stk  ; 
        
        
        for(int i = 0; i < s.size() ; i++){
            
            if(s[i] == '(' || s[i]== '{' || s[i] == '[') 
                stk.push(s[i]) ; 
            else {
                
                if(!stk.empty()){
                    char t= stk.top() ;
                
                if(s[i] == ')' && t != '(') 
                    return false ;
                 if(s[i] == '}' && t != '{') 
                    return false ;
                if(s[i] == ']' && t != '[') 
                    return false ;
                 stk.pop() ;
                }
                
                else
                    return false ;
                
             
            }
           
           
        }
        
        if(!stk.empty()) 
            return false ;
        
        
        return true ;
        
    }
};