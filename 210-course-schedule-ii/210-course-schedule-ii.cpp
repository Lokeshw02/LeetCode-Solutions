class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      
        vector<vector<int>>graph(numCourses) ;
        
        vector<int>indegrees(numCourses,0) ;
        
        vector<int> res  ;
        int count = 0  ;
        
        //Explicit graph creation 
        for(int i = 0 ; i< prerequisites.size() ; i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]) ;
            indegrees[prerequisites[i][0]]++ ;
        }
        
        
        queue<int>q ;
        
        for(int i = 0; i < indegrees.size() ; i++){
            if(indegrees[i] == 0)
                q.push(i) ;
        }
        
        while(!q.empty()){
            int t = q.front()  ;
            q.pop() ;
            count++ ;
            res.push_back(t) ;
            //Decrease the Indegrees of all the Adjecent  Nodes 
            
            for(auto &nbr : graph[t]){
                indegrees[nbr]-- ;
                if(indegrees[nbr] == 0)
                    q.push(nbr) ;
            }
          
        }
       return count == numCourses ? res : vector<int>() ;
    }
};