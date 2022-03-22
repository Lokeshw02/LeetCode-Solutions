class Solution {
public:
    int trap(vector<int>& height) {
    
        int l =0, r = height.size() -1, lvalue = height[0], rvalue = height[height.size()-1] ;
        int res = 0 ;
        
        while(l<r){
            
            if(lvalue<rvalue){
                int surplus = lvalue - height[l] ;
                if(surplus)
                    res += surplus ;
                l++ ;
                lvalue = max(lvalue,height[l]) ;
                    
            }
            
            else{
                
                int surplus = rvalue - height[r] ;
                if(surplus)
                    res += surplus ;
                r-- ;
                rvalue = max(rvalue,height[r]) ;
                
                
                
            }
        }
        
       return res ; 
        
    }
};