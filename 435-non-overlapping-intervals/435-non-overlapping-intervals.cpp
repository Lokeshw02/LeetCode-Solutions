class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int count = 0 ;
        
        int n = intervals.size() ;
        
        sort(intervals.begin(),intervals.end(),[=](vector<int>&t1,vector<int>&t2){
            
            return t1[1]<t2[1] ;
            
            
        });
        
        
        int prev = intervals[0][1] ;
        
        for(int i = 1; i<n ;i++){
            
            if(intervals[i][0] >= prev)
                prev = intervals[i][1] ;
            else 
                count++;    
            
        }
        
        return count ;
        
    }
};