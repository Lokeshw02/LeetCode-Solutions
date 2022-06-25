class Solution {
public:
    int hIndex(vector<int>& citations) {
        
//         int lo=0, hi = citations.size()-1, mid;
//         int len = citations.size();
            
//         while(lo<hi)
//         {
//             mid= lo + (hi-lo)/2 ;
            
//             if(citations[mid]>= (len-mid))
//                 hi = mid ;
            
//             else
//                 lo = mid + 1;
//         }
        
//         return len - lo;
        
        
        
        int left=0, len = citations.size(), right= len-1,  mid;
        while(left<=right)
        {
            mid=left+ (right-left)/2;
            if(citations[mid] >= (len-mid)) right = mid - 1;
            else left = mid + 1;
        }
        return len - left;
        
    }
};