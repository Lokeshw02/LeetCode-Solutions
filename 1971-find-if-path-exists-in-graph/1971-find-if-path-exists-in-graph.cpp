class Solution {
public:
    
    
    
   void dfs(int n, vector<vector<int>>& adjList,  vector<bool> &visited){
        
        visited[n] = true ;
        
        for(auto nbr : adjList[n]){
            if(!visited[nbr])
                dfs(nbr,adjList,visited) ;
        }
    }
    
    
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         vector<bool> visited(n, false) ;
         vector<vector<int>> adjList(n) ;
        
        for(auto nbr : edges){
            adjList[nbr[0]].push_back(nbr[1]) ;
            adjList[nbr[1]].push_back(nbr[0]) ;
        }
        
        dfs(source,adjList,visited) ;
        
        return visited[destination] ;
        
        
        
    }
};