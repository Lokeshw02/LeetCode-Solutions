class Solution {
public:
    
    bool isCycle(int n, vector<vector<int>>&adjList, vector<bool> &visited,  vector<bool>& path){
        
        visited[n] = true ;
        path[n] = true ;
        
        bool t = false ;
        
        //Go thorugh all thr neighbours of n 
        
        for(auto &nbr : adjList[n]){
        //path 
            if(path[nbr]) return true ;
            //Otherwise traverse this edge 
            if(!visited[nbr]) 
                t = t || isCycle(nbr,adjList,visited,path) ;
            if(t) return true ;
        }
        
        path[n] = false ;
        
        return t ;
    }
    
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adjList(numCourses) ;
      //Create a graph 
        for(auto &nbr : prerequisites){
            adjList[nbr[1]].push_back(nbr[0]) ;
        }
        
        vector<bool> visited(numCourses,false), path(numCourses,false) ;
        
        bool t = false ;
        
        
        for(int i = 0 ; i < numCourses ;i++){
            if(!visited[i]){
                t = t || isCycle(i,adjList,visited,path)  ;
                
                if(t) return false ;
            }
        }
        
        return !t ;
    }
};