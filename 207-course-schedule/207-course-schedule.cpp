class Solution {
public:
    
    bool isCycle(int n,vector<vector<int>>&adjList,vector<bool> &visited, vector<bool> & path ){
        
        visited[n] = true ;
        path[n] = true ;
        
        bool t1 = false ;
        
       //Go through the nbrs 
        
        for(auto &nbr : adjList[n]){
            
            //If cycle 
            if(path[nbr]) 
                return true ;
            //else travesrse through the edge 
            
            if(!visited[nbr]) 
            t1 = t1 || isCycle(nbr,adjList,visited,path) ;
            
            if(t1) return true ;
            
            
        }
        
        path[n] = false ;
            
        return t1 ;
    }
    
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adjList(numCourses) ;
        vector<bool> visited(numCourses), path(numCourses) ;
        
        for(auto &prereq : prerequisites ){
            adjList[prereq[1]].push_back(prereq[0]) ;
        }
        
        bool t = false ;
        for(int i = 0; i < numCourses; i++ ){
            
            if(!visited[i]){
                t = t || isCycle(i,adjList,visited,path) ;
                
                if(t) return false ;
            }
        }
        
        return !t ;
    }
};