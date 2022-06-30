class Solution {
public:
    
    
    
    
    
    int findPairs(vector<int>& nums, int k) {
        
        map<int,int> m ;
        
        
        
        for(int i =0 ; i <nums.size() ; i++){
            
            m[nums[i]]++ ;
            
           
            
        } 
        
        int count = 0 ;
       
        for(auto i = m.begin(); i!= m.end(); i++){
            
            
            if(k==0)
            {    
                if(i->second > 1)
                count++;
            }
            
            else if(m.find( (k + i->first)) != m.end()) 
                count ++ ;
            
        }
        
        
        return count ;
        
        
    }
};