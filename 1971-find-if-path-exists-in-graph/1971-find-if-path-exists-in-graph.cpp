class Solution {
public:
    
    void dfs(int n, vector<vector<int>>& edges, vector<bool> &visited, vector<vector<int>>&adjList ){
        visited[n] = true ;
        
        for(auto &t : adjList[n]){
            if(!visited[t])
                dfs(t,edges,visited,adjList) ;
        }
    }
    
    
    
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       
        vector<vector<int>>adjList(n) ; 
        vector<bool>visited(n,false) ;
        
        for(auto &nbr : edges){
            adjList[nbr[0]].push_back(nbr[1]) ;
            adjList[nbr[1]].push_back(nbr[0]) ;
            
        }
            
        dfs(source,edges,visited,adjList) ;
        
        return visited[destination] ;
        
        
       
        }
};