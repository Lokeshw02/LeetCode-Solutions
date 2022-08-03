class Solution {
public:
    
    
    bool isCycle(int n, vector<bool>& visited, vector<bool>&path, vector<vector<int>>&adjList){
        
        visited[n] = true ;
        path[n] = true ;
        
        bool t = false ;
        
        for(auto &nbr : adjList[n]){
            // If cycyle Exists 
            if(path[nbr]) 
                return true ;
            //Otgherwise travverse this edge if ot viviste d
            
            if(!visited[nbr]){
                t = t || isCycle(nbr,visited,path,adjList) ;
            }
            
            if(t)
                return true ;
            
            
        }
        path[n] = false ;
        
        return t ;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
        vector<vector<int>>adjList(numCourses) ;
        
        for(auto & pre : prerequisites ){
            adjList[pre[1]].push_back(pre[0]) ;
            
        }
        
        vector<bool> visited(numCourses,false) , path(numCourses, false); 
        
        bool t = false ;
        
        for( int i = 0 ; i < numCourses ; i++){
            if(!visited[i])
                t = t || isCycle(i,visited, path,adjList) ;
            
            if(t)
                return false ;
        }
        
        return !t ;
        
        
    }
};