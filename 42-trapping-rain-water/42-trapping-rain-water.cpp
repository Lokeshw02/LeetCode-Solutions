class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() -1 , lvalue = height[0] , rvalue = height[r] , surplus = 0 ;
        int res = 0 ;
        
        
        while(l<r){
            
            if(lvalue<rvalue){
                surplus = lvalue - height[l] ;
                if(surplus>0) 
                    res += surplus;
                l++ ;
                lvalue = max(lvalue,height[l]) ;
            }
            else{
                surplus = rvalue - height[r-1] ;
                if(surplus>0) res += surplus ;
                r-- ;
                rvalue = max(rvalue,height[r]);
            }
            
            
            
            
            
            
        }
        return res ;
    }
};