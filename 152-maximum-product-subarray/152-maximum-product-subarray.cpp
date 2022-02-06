class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(),i ,res = INT_MAX ;
        int minPrev, maxPrev, minCurr,maxCurr ;
        minPrev = nums[0] ; 
        maxPrev = nums[0] ;
        res = maxPrev ;
        
        for(int i =1;i<n;i++){
            maxCurr = max(nums[i],max(nums[i]*maxPrev,nums[i]*minPrev));
            minCurr = min(nums[i],min(nums[i]*maxPrev,nums[i]*minPrev));
            
            res = max(res,maxCurr) ;
            maxPrev = maxCurr ;
            minPrev = minCurr  ;
            
            

        }
        return res;
    }
};