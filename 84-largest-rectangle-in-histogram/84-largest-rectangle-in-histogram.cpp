class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() ;
        int max_area = 0, area_top = 0 ;
        stack<int> stk ;
        int i, tp ;
        i = 0 ;
        
        while(i<n){
            
            if(stk.empty() || heights[stk.top()] <= heights[i]) {
               stk.push(i) ;
                i++ ;
            }
            else{
                
                tp = stk.top() ;
                stk.pop() ;
                
                if(!stk.empty())
                area_top = heights[tp]*(i - stk.top() -1) ; 
                else
                    area_top = heights[tp]*i ;
                
                max_area = max(max_area,area_top) ;
                
            }
                
            
        }
        
        while(!stk.empty()){
            tp = stk.top() ;
            stk.pop() ;
            
            if(!stk.empty())
                area_top = heights[tp]*(i - stk.top() -1) ; 
                else
                    area_top = heights[tp]*i ;
                
            max_area = max(max_area,area_top) ;
            
        }
        
        return max_area ;
    }
};