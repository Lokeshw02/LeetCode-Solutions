class Solution {
public:
    
    void merge(vector<int>& nums, int l , int r, int mid){
        
        int i =  l, j = mid +1 ;
        vector<int> temp ;
        
        if(l >=r )
            return ;
        
        while( i <= mid && j <= r){
            
            if(nums[i] < nums[j]){
                temp.push_back(nums[i]) ;
                i++ ;
            } 
            else{
            temp.push_back(nums[j]) ;
                j++ ;
            }
        }
        
        
        if(i > mid){
            while(j <= r){
                temp.push_back(nums[j]) ;
                j++ ;
            }
        }
        else{
            while(i <= mid){
                temp.push_back(nums[i]) ;
                i++ ;
            }
        }
        
        int k = 0 ;
        
        for(int i = l ; i <= r ; i++){
            
            nums[i] = temp[k++] ;
 
        }
    }
    
    
    void mergesort(vector<int>&nums, int l , int r){
        
        
        if(l >= r) 
            return ;
        
        int mid = (l + r)/2 ;
        
        
        mergesort(nums,l,mid) ;
        mergesort(nums,mid+1,r) ; 
        merge(nums,l,r,mid) ;
        
        
    }
    
    
    
    vector<int> sortArray(vector<int>& nums) {
        
        int n = nums.size() ;
        
        mergesort(nums,0,n-1) ; 
        
        return nums ;
        
    }

    
};