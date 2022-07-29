class Solution {
public:
    
    int summer(int a){
        
        int sum = 0, r ; 
        
        while(a){
            int r = a%10 ;
            a = a/10 ;
            sum += r ;
        }
        
        
        
        return sum ;
        
    }
   
    
    
    int maximumSum(vector<int>& nums) {
        
        unordered_map<int,vector<int>> m ;
         int max_ = INT_MIN ;
        
        for(int i = 0 ; i <nums.size() ; i++){
            m[summer(nums[i])].push_back(nums[i]) ; 
            
        }
        
        for( auto it = m.begin() ; it != m.end() ; it++){
            
           if(it->second.size() > 1){
               sort(it->second.begin(), it->second.end()) ;
               max_ = max(it->second[it->second.size()-2] + it->second.back(), max_) ;
           }
            
            
              
            
        }
        
        
        
        return max_ == INT_MIN ? -1 : max_;
    }
};