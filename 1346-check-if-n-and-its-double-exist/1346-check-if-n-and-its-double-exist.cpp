class Solution {
public:
    
    int BS(vector<int>& arr, int s ){
        
        int lo = 0 ;
        int hi = arr.size() -1 ;
        
        while(lo<hi){
            
            int mid = lo + (hi-lo)/2 ;
            
            if(arr[mid]>=2*s)
                hi =  mid ;
                
            else 
                lo = mid +1  ;
            
                    
            
        }
        
        if(arr[lo] == 2*s) 
            return lo ;
        
        return -1 ;
        
        
    }  
    
    
    
    bool checkIfExist(vector<int>& arr) {
        
        sort(arr.begin(),arr.end()) ;
        
        bool res = false ;
          
        for(int i =0 ; i <arr.size(); i++){
            
           
            int temp = BS(arr,arr[i]) ;
            
            
           if(temp != -1 && i != temp ){
               res = true ;
               break ;
           } 
        }
        
       return res ; 
        
    }
};