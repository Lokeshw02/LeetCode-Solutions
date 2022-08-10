class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size() -1 ;
        int k = 0 ;
       
        
        for(int i = 1 ;i< nums.size(); i++){
            
            if(nums[i] == nums[i-1]) 
                k++ ;
            
            nums[i  - k] = nums[i] ;
        }
        
        return nums.size() - k ;
        
    }
};