class Solution {
public:
    
    vector<vector<int>>dirs = {{1,0},{-1,0},{0,1},{0,-1}} ;
    
   void dfs(vector<vector<int>>&heights,vector<vector<int>>&oceans,int i,int j,int n,int m)
    {
        if(i<0 || i>n-1 || j<0 || j>m-1) return; 
       
        if(!oceans[i][j])
        {
            oceans[i][j]=1; 
            
            for(auto &dir : dirs){
                int x = i + dir[0] ;
                int y = j + dir[1] ;
                
                if(x < n && x >= 0 && y < m && y >= 0 && heights[x][y]>=heights[i][j] )
                    dfs(heights,oceans,x,y,n,m) ;
            }
            
            
        }
    }
    
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = heights.size() ;
        int m = heights[0].size() ;
        
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));
        vector<vector<int>> result ;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0){
                    if(!pacific[i][j])
                    {
                        dfs(heights,pacific,i,j,n,m);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==n-1 || j==m-1){
                    if(!atlantic[i][j])
                    {
                        dfs(heights,atlantic,i,j,n,m);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    result.push_back({i,j});
            }
        }
        return result;

             
      
      
        
    }
};