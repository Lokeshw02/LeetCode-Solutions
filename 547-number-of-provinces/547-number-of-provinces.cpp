class Solution {
public:
    
    void dfs(vector<vector<int>>& graph, vector<bool>&visited, int n ){
        
        visited[n] = true ;
        
        for(int j = 0; j< graph[0].size(); j++){
            if(!visited[j] && graph[n][j] == 1)
                dfs(graph,visited,j) ;
            }
    }
    
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<bool> visited(isConnected.size(),false) ;
        
        int count  = 0 ;
        
        for(int i =0 ; i <isConnected.size(); i++ ){
            
            if(!visited[i]){
                dfs(isConnected,visited,i) ;
                count ++ ;
            }
        }
        return count ;
    }
};