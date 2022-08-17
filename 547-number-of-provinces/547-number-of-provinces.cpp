class Solution {
public:
    
    void dfs(vector<vector<int>>&graph, vector<bool>& visited, int n){
        
        visited[n] = true; 
        
        // GO through  the neighbours 
        
        for(int i = 0 ; i < graph[0].size() ; i++){
            
            if(graph[n][i] && !visited[i]) 
                dfs(graph,visited,i) ;
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false) ;
        
       int count = 0 ;
        
        for(int i = 0; i < isConnected.size() ; i++){
            if(!visited[i]){
                 dfs(isConnected, visited,i) ;
                 count++ ;
            }
                
          
        }
        
        return count ;
        
        
    }
};