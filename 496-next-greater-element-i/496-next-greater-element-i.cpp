class Solution {
public:
    
    vector<int>NGE(vector<int>&nums){
        int n = nums.size() ;
        vector<int>res ;
        stack<int> stk ;
        
        for(int i = n-1 ; i>= 0 ;i--){
            
            if(stk.empty()) 
                res.push_back(-1) ;
            else if(!stk.empty() && stk.top() > nums[i])
                res.push_back(stk.top()) ;
            else if(!stk.empty() && stk.top() <= nums[i]){
                
                while(!stk.empty() && stk.top() <= nums[i]) 
                    stk.pop() ;
                
                if(stk.empty()) 
                    res.push_back(-1) ;
                else
                    res.push_back(stk.top()) ;
            }
            
            stk.push(nums[i]) ;
             
        }
    
    reverse(nums.begin(),nums.end()) ;
        
        return res ;
    
    }
    
    
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m ;
         vector<int> res ;
        
        //Next greater element for nums2 
        
        vector<int> t = NGE(nums2) ;
        
        for(int i = 0; i < nums2.size() ; i++){
            m[nums2[i]] = i ;
        }
        
        for(int j = 0 ; j < nums1.size(); j++){
            res.push_back(t[m[nums1[j]]]) ;
        }
       
        return res ;
        
        
    }
};