class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int count = 0 ;
       int votes = 0 ;
      int candidate = -1 ;
        
        
        for(int i = 0 ; i<nums.size() ; i++){
            if(votes == 0) 
            {
                candidate = nums[i] ;
                votes = 1 ;
            }
            else{
                if(nums[i] == candidate)
                    votes++ ;
                else
                    votes-- ;
            }
        }
        
        count = 0 ;
        
        for(int j = 0 ; j < nums.size() ; j++){
            if(nums[j] == candidate)
                count++ ;
        }
        
        if(count > nums.size()/2 ) return candidate ; 
        
        return -1 ;
    }
};