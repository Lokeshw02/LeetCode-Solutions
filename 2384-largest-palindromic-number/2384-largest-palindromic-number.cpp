class Solution {
public:
    string largestPalindromic(string num) {
        
    unordered_map<char,int> m ;
    
        for(char c : num){
            m[c]++ ;
        }
        
        string front  = "", back = "" ;
        
        for(char i = '9' ; i >= '0' ;i--){
            
            if(front == "" && i == '0')
                continue ;
            
            if(m.find(i) != m.end())
            while(m[i] > 1){
                front.push_back(i) ;
                back.push_back(i) ;
                m[i] -= 2 ;
            }
        }
        
        for(char i = '9' ; i >= '0' ;i--){
            
             if(m.find(i) != m.end()){
                 if(m[i]> 0)
                 {front.push_back(i) ;
                 break ;}
             }
             
        }
        
        reverse(back.begin(), back.end()) ;
        
        string res = front + back ;
        
        return res ;
        
    }
};