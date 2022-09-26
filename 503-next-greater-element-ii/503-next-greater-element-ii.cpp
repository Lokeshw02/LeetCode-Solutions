class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk ;
        int n = nums.size() ;
        vector<int>ans(n,-1) ;
        
        for(int i = 0; i< 2*n ; i++){
            int j  = i%n ;
            
            while(!stk.empty() && nums[stk.top()] < nums[j] ){
                ans[stk.top()] = nums[j] ;
                stk.pop() ;
            }
            
            stk.push(j) ;
        }
        return ans ;
    }
};