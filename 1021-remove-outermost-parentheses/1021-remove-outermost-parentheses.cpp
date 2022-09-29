class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int n = s.size() ;
        stack<char>stk ;
        string v ;
        
        for(int i = 0; i < n ; i++){
            
            if(s[i] == '('){
                if(!stk.empty()){
                   v.push_back(s[i]) ;
                }
                 stk.push(s[i]) ;
            }
            else{
                stk.pop() ;
                if(!stk.empty()){
                    v.push_back(s[i]) ;
                }
            }
        }
        
        return v ;
    }
};