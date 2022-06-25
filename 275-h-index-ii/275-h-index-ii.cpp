class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int lo=0, hi = citations.size()-1, mid;
        int len = citations.size();
            
        while(lo<=hi)
        {
            mid= lo + (hi-lo)/2 ;
            
            if(citations[mid]== (len-mid)) return citations[mid];
            else if(citations[mid] > (len-mid)) hi = mid - 1;
            else lo = mid + 1;
        }
        
        return len - (hi+1);
        
    }
};