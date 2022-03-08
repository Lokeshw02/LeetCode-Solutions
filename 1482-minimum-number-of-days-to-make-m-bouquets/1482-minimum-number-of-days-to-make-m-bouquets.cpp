class Solution {
public:
    
    bool check(vector<int>&nums, int m , int k, int mid){
        int count = 0;
        int currCount = 0 ;
        
        for(int i =0;i<nums.size();i++){
            
            if(nums[i]<=mid){
                currCount++ ;
                if(currCount == k) {
                    count ++ ;
                    currCount =0 ;
                }
            }
            else{
                currCount = 0 ;
            }
        }
        
        return count>=m ;
    }
    
    
    
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo = *min_element(bloomDay.begin(),bloomDay.end()) ;
        int hi = *max_element(bloomDay.begin(),bloomDay.end()) ;
        int mid ,res;
        
        //FF*TTT*
        
        while(lo<hi){
            
        mid = lo +  (hi-lo)/2 ;
            
        if(check(bloomDay,m,k,mid))
            hi = mid;
        else
            lo = mid+1 ;
                                   
            
        }
       
        
        if(check(bloomDay,m,k,lo)) return lo ;
        return -1 ;
      
    }
};