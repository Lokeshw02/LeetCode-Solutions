class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mask = 1 ; 
        int res = 0 ;
        
        for(int i = 0 ; i <32 ; i++){
            mask = 1 << i ;
            int count = 0 ;
            
            for(int j = 0 ; j < nums.size(); j++){
             int t = nums[j]&mask ;
             
                if(t) 
                    count++ ;
            }
            if(count%3 != 0) 
                res = res | mask ;
            
        }
        return res ;
        
    }
};