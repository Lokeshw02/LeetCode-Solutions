class Solution {
public:
    int minSwaps(string s) {
        int swaps = 0, balance = 0 ,i, j = s.length() -1 ;
        
        for(i = 0;i<s.length();i++){
            
            if(s[i] == '['){
                balance++ ;
            }
            else{
                balance -- ;
                if(balance<0){
                    while(i<j && s[j] != ']')
                        j -- ;
                    swap(s[i],s[j] ) ;
                    swaps++ ;
                    balance = 1 ;
                 }
                
                
                
            }
            
        }
        
        return swaps ;
    }
};