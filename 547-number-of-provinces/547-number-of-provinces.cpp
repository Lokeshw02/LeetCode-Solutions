class Solution {
public:
    
    void dfs(int n, vector<bool>&visited , vector<vector<int>> & isConnected ){
        
        visited[n] = true ;
        
        for(int j = 0; j<isConnected[n].size();j++){
            if(isConnected[n][j] && !visited[j])
                dfs(j,visited,isConnected ) ;
            
        }
    }
    
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>visited(isConnected.size(),false) ;
        int res = 0 ;
        
        for(int i =0; i<isConnected.size() ;i++){
            if(!visited[i]){
                dfs(i,visited,isConnected) ;
                res++ ;
            }
        }
        return res ;
    }
};