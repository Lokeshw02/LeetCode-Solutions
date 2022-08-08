class Solution {
public:
    
      vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}} ;
    
    int maxDistance(vector<vector<int>>& grid) {
        
         int  n = grid.size() , m = grid[0].size() ;
        vector<vector<bool>>visited(n,vector<bool>(m,false)) ;
      //  vector<vector<int>>dist(n,vector<int>(m,0)) ;
        
        //q[0] -> x, q[1] ->y, q[2]-> level 
        
        int res = -1;
        
        queue<vector<int>>q ;
        
        //Push all the ones 
        for(int i =0; i< n ; i++){
            for(int j =0; j<m ; j++){

                if(grid[i][j] == 1){
                    q.push({i,j,0}) ;
                    visited[i][j] = true ;
                    //dist[i][j] = 0 ;
                }
                 
            }
        }
        //Read to Start BFS 
        while(!q.empty()){
            vector<int> t = q.front();
            q.pop() ;
            
            //Push its nbrs 
            
            for(auto &drs : dirs){
                int x = t[0] + drs[0] ;
                int y = t[1] + drs[1] ;
                
                if(x<0 || x>=n || y<0 || y>= m)
                    continue ;
                
                if(visited[x][y]) continue ;
                
                q.push({x,y,t[2]+1}) ;
                visited[x][y] = true ;
                res = max(res,t[2] + 1)  ;
                
            }
        
        }
            
       return res ; 
    }
};