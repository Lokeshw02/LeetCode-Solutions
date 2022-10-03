class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int totalxor = 0 ;
        int g1= 0, g2 = 0 ;
        
        for(int i = 0 ; i < nums.size() ; i++){
            totalxor ^= nums[i] ;
        }
        
        unsigned int mask = totalxor&(-totalxor) ; 
        
//         for(int i = 0; i<= 32; i++){
            
//             if(totalxor&(1<<i)) {
//                 mask = (1<<i); 
//                 break ;
//             }
                
//         }
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]&mask) 
                g1= g1^nums[i];
            else
                g2 = g2^nums[i] ;
        }
        
        return {g1,g2} ;
    }
};