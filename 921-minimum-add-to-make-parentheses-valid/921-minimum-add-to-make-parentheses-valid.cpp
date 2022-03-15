class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int leftExtra = 0, rightExtra = 0 ,i;
        
        for(i = 0;i<s.length();i++){
            
            if(s[i] == '('){
                leftExtra++ ;
            }
            else{
                leftExtra-- ;
                
                if(leftExtra < 0){
                    rightExtra++ ;
                    leftExtra = 0 ;
                }
                    
                
                
            }
            
            
            
        }
        
        return leftExtra + rightExtra ;
    }
};