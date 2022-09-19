class Solution {
public:
    int trap(vector<int>& height) {
        int lo = 0, hi = height.size() -1, lval = height[0], rval = height[height.size() -1 ] ;
        
        int res = 0 ;
        
        while(lo <hi){
            
            if(lval < rval){
                int surplus = lval - height[lo] ;
                if(surplus){
                    res += surplus ;
                    
                }
                lo++ ;
                lval = max(lval,height[lo]) ;
            }
            
            else{
                int surplus = rval - height[hi] ;
                if(surplus) 
                    res += surplus ;
                hi-- ;
                rval = max(height[hi],rval) ;
            }
        }
        
        return res ;
    }
};