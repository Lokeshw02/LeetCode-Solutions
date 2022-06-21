class Solution {
public:
    
    
    bool isValid(vector<int>&arr,int n, int d){
        
        int lo = 0 ;
        int hi = arr.size() -1 ;
        
        int mid ;
        
        while(lo<hi){
            
            mid = lo + (hi-lo)/2 ;
                
            if (arr[mid] >= n) 
                hi = mid ;
            else
                lo = mid + 1 ;

        }
        
        if(lo != 0)
        return min(abs(arr[lo]-n),abs(arr[lo-1]-n)) > d ;
        
        else 
            return abs(arr[lo]-n) > d ;
        
           
    }
    
    
    
    
    
    
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
       
        sort(arr2.begin(),arr2.end()) ;
        
        int t = 0 ;
        
        for(int x : arr1){
           if(isValid(arr2,x,d)) 
               t++ ;
            
        }
        
        return t ;
        
    
    }
};


