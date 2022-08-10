class Solution {
public:
    
    bool checker(vector<int>&nums , int k ){
        
        for(int i = 0 ;i < nums.size()-1 ; i++){
            if(nums[i+1] -nums[i] <= k) 
                return true ;
        }
        
        return false ;
    }
    
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       
        unordered_map<int,vector<int>> m ;
        
        for(int i = 0 ; i< nums.size() ; i++){
            
            if(m.find(nums[i]) == m.end()) 
                m[nums[i]] = {i} ;
            
            else{
                 m[nums[i]].push_back(i) ;
            }
            
            
            
        }
        
        for(auto it = m.begin() ; it != m.end() ;it++){
            
            if(it->second.size() > 1) {
                
               // sort(it->second.begin() ,it->second.end()) ;
                    if(checker(it->second, k))
                    return true ;
            
                
        }
        }
            
            return false ;
    }
};