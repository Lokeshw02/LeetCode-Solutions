class Solution {
public:
    
    
    bool BS(vector<int>& bobSizes, int s){
        
        
        
        
        int lo = 0 ;
        int hi = bobSizes.size()-1 ;
        
        
        while(lo<hi){
            
            int mid = lo + (hi-lo)/2 ;
            
            
        if(bobSizes[mid] >= s )
            hi = mid ;
            
        else
            lo = mid +1 ;
        }
        
        
        
        
      return bobSizes[lo] == s ; 
         
        
    }
    
    
    
 
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        
        int alicSum = 0, bobSum = 0 ;
        
        vector<int>res;
        
        for(int x : aliceSizes) alicSum += x ;
        
        for(int x : bobSizes) bobSum += x ;
        
//         unordered_map<int,int> m ;
        
//         for(int y : bobSizes) m[y] = 1 ;
        
        
        sort(bobSizes.begin(),bobSizes.end()) ;
        
     
        
        for(int i =0 ;i < aliceSizes.size();i++){
            
//             //If present 
//             if(m.find(aliceSizes[i]+ (bobSum-alicSum)/2 ) != m.end()){
               
            
//              res.push_back(aliceSizes[i]) ;
//              res.push_back(aliceSizes[i]+ (bobSum-alicSum)/2) ;
            
                
//              break ;
                
//             }
            
            if(BS(bobSizes,aliceSizes[i]+ (bobSum-alicSum)/2 )){
                
                res.push_back(aliceSizes[i]) ;
                res.push_back(aliceSizes[i]+ (bobSum-alicSum)/2) ;
                break ;
               
            }
            
            else{
                
                continue ;
            }
                
            
            
                
    
                
            }
        
        
        
                      
    
        
        return res ; 
        
    }
};