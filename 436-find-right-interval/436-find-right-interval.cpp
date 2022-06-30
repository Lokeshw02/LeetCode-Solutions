class Solution {
public:

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        unordered_map< int, int> m ;
        
        vector<int> res(intervals.size(), -1) ;
        
        //Store Initial Value - Index Pair 
        
        for(int i = 0 ; i< intervals.size() ; i++){
            
            m[intervals[i][0]] = i ;
            
        }
        
        //Sort the Vector : On the basis of the first elememt 
        
        sort(intervals.begin(),intervals.end()) ;
        
        for( int i = 0 ; i< intervals.size() ; i++){
            
            int lo = 0 ;
            int hi = intervals.size() -1 ;
            
            int mid ;
            
            while(lo<hi){
                
                mid = lo +(hi-lo)/2 ;
                
                if(intervals[mid][0] >= intervals[i][1] )
                    hi = mid  ;
                
                else
                    lo = mid +1  ;
                
                
                
            }
            
            if(intervals[lo][0] >= intervals[i][1]) 
                
                res[m[intervals[i][0]]] = m[intervals[lo][0]] ;
        
            
        }
        
        return res ;
        
               
    }
};