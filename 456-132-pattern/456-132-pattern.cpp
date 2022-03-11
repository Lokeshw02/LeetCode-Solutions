class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        vector<int>prefMin(nums.size()) ;
        
        prefMin[0] = nums[0] ;
        
        for(int i =1;i<nums.size();i++){
            prefMin[i] = min(prefMin[i-1],nums[i]) ;
        }
        
        stack<int>stk ;
        
        for(int j = nums.size()-1 ; j>=0 ;j--){
            while(stk.size()>0 && stk.top() <= prefMin[j])
                stk.pop() ;
            
            
            if(stk.size()>0 && stk.top()<nums[j]){
                return true ;
            }
             
            stk.push(nums[j]) ;
        }
        
        return false ;
    }
};