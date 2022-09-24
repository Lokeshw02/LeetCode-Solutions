class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minprev,maxprev,mincurr,maxcurr ;
        minprev = nums[0], maxprev = nums[0] ;
        int res = nums[0];
        
        for(int i =1; i < nums.size() ; i++){
            
            maxcurr = max(nums[i],max(nums[i]*maxprev,nums[i]*minprev)) ; 
            mincurr = min(nums[i],min(nums[i]*minprev,nums[i]*maxprev)) ;
            
            res = max(res,maxcurr) ;
            
            maxprev = maxcurr ;
            minprev = mincurr ;
            
        }
         
        return res ;
    }
};