class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        
        int alicSum = 0, bobSum = 0 ;
        
        vector<int>res;
        
        for(int x : aliceSizes) alicSum += x ;
        
        for(int x : bobSizes) bobSum += x ;
        
        unordered_map<int,int> m ;
        
        for(int y : bobSizes) m[y] = 1 ;
        
        
        
        
        
        for(int i =0 ;i < aliceSizes.size();i++){
            
            //If present 
            if(m.find(aliceSizes[i]+ (bobSum-alicSum)/2 ) != m.end()){
               
                
             res.push_back(aliceSizes[i]) ;
             res.push_back(aliceSizes[i]+ (bobSum-alicSum)/2) ;
            
                
             break ;
                
            }
                
    
                
            }
                       
            
    
    
        
        return res ; 
        
    }
};