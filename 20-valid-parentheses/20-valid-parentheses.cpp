class Solution {
public:
    bool isValid(string s) {
        
       // stack<char> stk ;
       for(int i = 0; i < s.length(); i++){
            
            if(s.length() == 0)
                return true;
            
            if(s[0] == ')' || s[0] == ']' || s[0] == '}')
                return false;
            if(s.back() == '(' || s.back() == '[' || s.back() == '{')
                return false;
            
            if(s[i] == ')'){
                if(s[i-1] == '('){
                   
                    s.erase(i-1,2);
                    i = 0;
                }
            }
            else if(s[i] == ']'){
                if(s[i-1] == '['){
                    //s.erase(i,1);
                     s.erase(i-1,2);
                    i = 0;
                }
            }
            else if(s[i] == '}'){
                if(s[i-1] == '{'){
                   // s.erase(i,1);
                    s.erase(i-1,2);
                    i = 0;
                }
            }
        }

    if(s.length() > 0)
        return false;
        
    else
        return true;
        
    }
};