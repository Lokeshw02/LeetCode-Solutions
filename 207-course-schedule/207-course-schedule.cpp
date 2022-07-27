class Solution {
public:
    
    bool isCycle(int n, vector<bool>& visited, vector<bool>& path, vector<vector<int>>& adjList){
        
        visited[n] = true ;
        path[n] = true ;
        
        bool t = false ;
        
        //Go through all the neighbours of n 
        
        for(auto &nbr : adjList[n]){
            //Cycle
            if(path[nbr])
                return true ;
            //Otherwise traverse this edge if not visiste 
            if(!visited[nbr])
                t = t || isCycle(nbr, visited, path, adjList) ;
            
            if(t)
                return true ;
        }
        
        path[n] = false ;
        
        return t ;
    }
    
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //Adjecency List 
        vector<vector<int>>adjList(numCourses) ;
        
        for(auto &prereq : prerequisites){
            //(a,b) is the prereq 
            //Add an edge from b to a 
            adjList[prereq[1]].push_back(prereq[0]) ;
            
        }
        
        vector<bool> visited(numCourses, false), path(numCourses,false) ;
        
        bool t = false ;
        
        for(int i =0 ; i < numCourses ; i++){
            if(!visited[i])
                t = t || isCycle(i, visited, path, adjList) ;
            
            if(t)
                return false ;
        }
        
        return !t ;
    }
};