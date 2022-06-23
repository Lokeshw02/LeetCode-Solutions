class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        
        int lo = 0 ;
        int hi = letters.size() ;
        
        int mid ;
        
        while(lo<hi){
            
            mid = lo + (hi-lo)/2 ;
                
            if(letters[mid]>target)
                hi = mid ;
            
            else 
                lo = mid+1 ;
           
        }
        
        
        
        
        
        
      
            return letters[(lo)%(letters.size())] ;
        
        
       
        
    }
};