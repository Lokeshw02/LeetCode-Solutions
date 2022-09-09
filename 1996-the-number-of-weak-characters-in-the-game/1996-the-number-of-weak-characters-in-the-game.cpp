class Solution {
public:
    
    static bool comp(vector<int>&a, vector<int>&b){
        
        if(a[0] != b[0]) 
            return a[0] < b[0]; 
        
        return a[1] > b[1] ;
    }
    
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comp) ;
       
        int count = 0 ;
        
        int n = properties.size() ;
        
        int max_ = properties[n-1][1] ;
        
        for(int i = n-2; i >=0 ; i--){
            
            if(properties[i][1] <  max_) 
                count++ ;
            
            max_ = max(max_,properties[i][1]) ;
        }
            
            
        return count ;
    }
};