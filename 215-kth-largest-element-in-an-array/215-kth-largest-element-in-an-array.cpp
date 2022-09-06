class Solution {
public:
    
    int counter(vector<int> &A, int x){
    
    int count = 0 ;
    
    for(int i=0 ; i < A.size() ; i++){
        if(A[i] <= x) 
        count++ ;
    }
    return count ;
}
    
    
    
    int findKthLargest(vector<int>& nums, int k) {
        
    int hi = *max_element(nums.begin(),nums.end()) ;
    int lo = *min_element(nums.begin(),nums.end()) ;
    int mid ;
    int n = nums.size() ;
        
        
        while(lo <= hi){
            
            mid = lo + (hi-lo)/2  ;
            
            if(counter(nums,mid) < n-k +1 )
                lo = mid +1 ;
            else {
                if(counter(nums,mid-1) < n-k +1 )
                    return mid ;
                else
                    hi = mid -1 ;
            }
                
                
        }
        
        return mid ;
    }
};