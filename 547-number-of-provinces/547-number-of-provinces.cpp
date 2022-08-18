class Solution {
public:
    
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int n ){
        visited[n] = true ;
        
        for(int i = 0; i < isConnected.size() ; i++){
            if(!visited[i] && isConnected[n][i])
                dfs(isConnected, visited,i) ;
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ;
        vector<bool> visited(n,0) ;
        int count = 0 ;
        
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                
                dfs(isConnected,visited,i) ;
                count++ ;
            }
            

        }
        
     return count ;
    }
};