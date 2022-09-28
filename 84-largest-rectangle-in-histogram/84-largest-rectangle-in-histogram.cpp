class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int i = 0 ;
        stack<int> stk;
        int max_area = -1 , area_top;
        int n = heights.size() ;
        int tp ;
        
        while(i<n){
            
            if(stk.empty() || heights[stk.top()] <= heights[i]){
                stk.push(i) ;
                i++ ;
                
            }
            
            else{
                tp = stk.top() ;
                stk.pop() ;
                
                if(stk.empty()) 
                    area_top = heights[tp]*i ; 
                else
                    area_top = heights[tp]*(i - stk.top() - 1)  ;
                
                max_area = max(area_top,max_area) ;
                
            }
        }
        
        while(!stk.empty()){
            tp = stk.top() ;
            stk.pop();
            
            if(stk.empty()) 
                area_top = heights[tp]*i ;
            else
                area_top = heights[tp]*(i-stk.top()-1) ; 
            
            max_area = max(area_top,max_area) ;
        }
        
        return max_area ;
        
    }
};