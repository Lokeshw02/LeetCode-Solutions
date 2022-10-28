class Solution {
public:
    vector<vector<int>>dirs = {{0,-1},{0,1},{-1,0},{1,0}} ;
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        
        if(n ==1 && m ==1 ) 
            return 0 ;
        vector<vector<int>>visited(m,vector<int>(n,-1)) ;
        
        queue<vector<int>> q ; 
        //x, y, steps, k 
        
        visited[0][0] = k ;
        q.push({0,0,0,k}) ;
        
        while(!q.empty()) {
            vector<int> t = q.front() ;
            q.pop() ;
            int row = t[0], col = t[1] , steps = t[2], obs = t[3] ;
            
            if(row == m-1 && col == n-1 ) 
                return steps ;
            
            if(grid[row][col] == 1){
                
                if(obs == 0 ) 
                    continue ;
                obs-- ;
                
            } 
            
            for(int i = 0; i < 4 ; i++){
                
                int x = row + dirs[i][0] ;
                int y = col + dirs[i][1] ;
                
                if( !(x < 0 || y < 0 | x >= m || y >= n) && visited[x][y] < obs) 
                 
                   {visited[x][y] = obs ;
                    q.push({x,y,steps+1,obs}) ;}
                    
            }
                
        }
        
        
        
        return -1 ;
        
    }
};