class Solution {
public:
    
     vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}} ;
    
    
    int maxDistance(vector<vector<int>>& mat) {
        
         int  n = mat.size() , m = mat[0].size(), dist = -1 ;
        vector<vector<bool>>visited(m,vector<bool>(n,false)) ;
      
        
        //q[0] -> x, q[1] ->y, q[2]-> level 
        
        
        queue<vector<int>> q ;
        
        //Push all the 1s 
        for(int i =0; i< m ; i++){
            for(int j =0; j<n ; j++){

                if(mat[i][j] == 1){
                    q.push({i,j,0}) ;
                    visited[i][j] = true ;
                    
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
                
                if(x<0 || x>=m || y<0 || y>= n) continue ;
                   
                
                
                if(visited[x][y]) continue ;
                
                q.push({x,y,t[2]+1}) ;
                visited[x][y] = true ;
                dist = max(dist,t[2] + 1 ) ;
                
            }
        
        }
            
        return dist ;
        
    }
};