class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0) return 0 ;
        if(nums.size() == 1) return 1 ;
        
//         if(nums.size() == 2){
            
//             if(nums[0] == nums[1] ) return 1 ;
//         }
        
        unordered_map<int,int> m ;
        int ans = 0 ;
        
        for(int x : nums){
            m[x]++ ;
        }
       
        for(int i = 0; i < nums.size() ; i++){
            
            int v = nums[i] ;
            int temp = 1 ;
            
            
        
        
        if(m.find(v-1) == m.end() && m.find(v+1) != m.end()) {
            while(m.find(v+1) != m.end()) 
            {
                temp++ ;
                v++ ;
            }
            
           
        }
            
             ans = max(ans,temp) ;
            
        }
        
        
        return ans ;
        
        
        
    }
};