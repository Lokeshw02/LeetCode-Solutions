class Solution {
public:
     
    int maxSumMinProduct(vector<int>& nums) {
        
        stack<int> stk ;
        int n = nums.size() ;
        
        //Genereate nearest smaller to the left{index} 
        vector<int>left_nearest(n,-1) ;
        
        for(int i = 0; i < n ; i++){
            
            while(!stk.empty() && nums[stk.top()] >= nums[i] ){
                stk.pop() ;
            }
            
            if(!stk.empty()) 
                left_nearest[i] = stk.top();
            
            stk.push(i) ;    
           }
        
        //Clear stack 
         while(!stk.empty()) stk.pop() ;
        
        //Genrate nearest smaller to right{index} 
        
        vector<int>right_nearest(n,n) ;
        
        for(int i = n-1; i>=0 ; i--){
            while(!stk.empty() && nums[stk.top()] >= nums[i]) 
                stk.pop() ;
            
           if (!stk.empty())  
               right_nearest[i] = stk.top() ;
            
            stk.push(i) ;
                
        }
        //Generate Prefix Array 
        vector<long long > prefix(n) ;
        
        for(int i = 0; i< n; i++){
            if(i==0) 
                prefix[i] = nums[i];
            else
                prefix[i] = prefix[i-1] + nums[i] ;
        }
        
        //Generate ANswers 
        
        long long ans = 0 ;
        
        for(int i = 0; i < n ; i++){
            
            int left = left_nearest[i]  ; 
            int right = right_nearest[i]  ; 
            
            ans = max(ans, (long long) nums[i]*(prefix[right-1] - (left >=0 ? prefix[left] :0))) ;
            
            
        }
        
        return int(ans % int(1e9 + 7)) ;
      
    }
};