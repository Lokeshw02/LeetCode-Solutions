class Solution {
public:
    
    static bool comp(vector<int>&a, vector<int>&b){
        
        if(a[0] != b[0]) 
            return a[0]> b[0]; 
        
        return a[1] < b[1] ;
    }
    
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comp) ;
        int max_ = INT_MIN ;
        int count = 0 ;
        
        for(auto &p : properties){
            
            if(max_ > p[1])
                count++ ;
            else
                max_ = p[1] ; 
        }
       
        return count ;
    }
};