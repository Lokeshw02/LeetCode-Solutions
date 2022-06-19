class Solution {
public:
    
    bool isPosssible(vector<int>& weights, int days, int mid){
        
        int x = 1 ;
        
        int sum = 0 ;
        
        for(int i = 0 ; i < weights.size(); i++){
            
            sum += weights[i] ;
            
            if(sum > mid){
                x++ ;
                sum = weights[i] ;
            }
            
            
        }
        
    return x<=days ;
        
        
    }
    
    
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int lo = *max_element(weights.begin(), weights.end());
        
        int total = 0 ;
        
        for(int x : weights) total += x ;
        
        int hi = total ;
        
        int mid ;
        
        while(lo<hi){
            
          mid = lo + (hi-lo)/2 ;
              
         if(isPosssible(weights,days,mid)) 
             hi = mid ;
         else 
             lo = mid +1 ;
              
                 
        }
        
       
        
        return lo ;
        
        
        
    }
};