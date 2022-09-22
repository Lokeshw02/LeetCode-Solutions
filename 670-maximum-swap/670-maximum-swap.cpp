class Solution {
public:
    int maximumSwap(int num) {
        
        string S = to_string(num) ;
        
         int max_no = -1, max_idx = -1, li = -1, ri = -1 ;
        
        for(int i = S.size() -1; i >= 0; i--){
            
            if(S[i]> max_no) {
                max_no = S[i] ;
                max_idx = i ;
                continue ;
                
            }
            
            
            if(S[i] < max_no){
                li = i ;
                ri = max_idx ;
            }
            
        }
            
        
            
            if(li == -1) 
            return stoi(S) ;
            
            swap(S[li],S[ri]) ;
            
            return stoi(S) ;
        
        
    }
};