class Solution {
public:
    
    int hasCycle(vector<vector<int>>& graph, vector<int>& visited, vector<bool>& path, int n){
        path[n] = true ;
        //Safe 1 // Unsafe 2 // Unvisited 0 
        
        int safe = 1 , t ;
        
        for(auto &nbr : graph[n]){
            
            if(path[nbr]) 
                safe = 2 ;
            else if (!visited[nbr]){
                t = hasCycle(graph, visited, path, nbr) ;
                if(t ==2) 
                    safe = t ;
            }
            else if(visited[nbr] == 2 )
                safe  = visited[nbr] ;
        }
        path[n]  = false ;
        visited[n] = safe ;
        
        return safe ;
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int numNodes = graph.size() ;
        vector<int> visited(numNodes,0) ;
        vector<bool> path(numNodes,0) ;
        
        vector<int>safeList  ; 
        
        for( int i =0 ; i < numNodes ; i++){
            if(!visited[i])
                int t = hasCycle(graph,visited,path,i) ;
        }
        
        for( int i =0 ; i < numNodes ; i++){
            if(visited[i] ==1 )
                safeList.push_back(i) ;
        }
        
        return safeList ;
    }
};