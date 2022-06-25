class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int lo = 0 ;
        int hi = numbers.size() -1 ;
        
        int mid ;
        
        while(lo<=hi){
            
        mid = lo + (hi-lo)/2 ;
            
            
        if(numbers[lo]+numbers[hi] == target)
            return {lo+1,hi+1} ;
            
        if(numbers[lo]+numbers[hi] > target) 
            hi = hi -1 ;
            
        else 
            lo = lo +1 ;
            
        }
        
       
            return {lo+1, hi+1} ;
        
    }
};