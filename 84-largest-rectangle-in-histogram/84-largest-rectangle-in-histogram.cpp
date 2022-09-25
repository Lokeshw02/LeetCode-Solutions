class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk ;
        int n = heights.size() ;
        int area_top, max_area = 0;
        int tp ;
        
        int i = 0 ;
        
        while(i<n){
            
            if(stk.empty() || heights[stk.top()] <= heights[i] ){
                 stk.push(i) ; 
                 i++ ;
            }
            
            else{
                tp = stk.top() ;
                stk.pop() ;
                
                //Calculate area
                if(!stk.empty())
                area_top =  heights[tp]*(i - stk.top()-1) ;
                else
                    area_top = heights[tp]*i ;
                
                max_area = max(max_area,area_top) ;
                
            }
                   
        }
        
        while(!stk.empty()){
            tp = stk.top() ;
            stk.pop() ;
            
            if(!stk.empty())
                area_top = heights[tp]*(i-stk.top()-1);
            else
                 area_top = heights[tp]*i ; 
            
            max_area = max(max_area,area_top) ;
        }
        
        return max_area ;
    }
};