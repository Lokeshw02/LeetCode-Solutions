class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       
       int n = nums1.size() ;
       int m = nums2.size() ;
       map<int,int> mp ;
        set<int> s ;
        
        
        
       for(int i = 0;i<n;i++){
           mp[nums1[i]]++ ;
       } 
       
        for(int i = 0;i<m;i++){
           if(mp.find(nums2[i]) != mp.end())
               s.insert(nums2[i]) ;
               
       } 
       
        vector<int>res(s.begin(),s.end()) ;
        
        return res ;
       
        
       
        
    }
};