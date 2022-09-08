class Solution {
public:
    
    double myPow2(double x, int n) {
        
        if(n == 0) return 1 ;
        
        double t = myPow2(x,n/2) ;
        
        if(n%2 == 0) return t*t ;
        
        else return x*t*t ;
        
        
    }
    
    
    
    double myPow(double x, int n) {
        
        if(n<0){
            x  = 1/x ;
        }
        
        double ans = myPow2(x,n) ;
        
        return ans ;
        
        
    }
};