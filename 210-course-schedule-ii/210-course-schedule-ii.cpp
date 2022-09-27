class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses ;
        vector<vector<int>>graph(n) ;
        vector<int>indegree(n,0) ;
        vector<int> res ;
        int count = 0 ;
        
        for(int i = 0; i < prerequisites.size() ; i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]) ; 
            indegree[prerequisites[i][0]]++ ;
        }
        
        queue<int>q ;
        
        for(int i = 0; i< n ; i++){
         if(indegree[i] == 0) 
             q.push(i) ;
        }
        
        while(!q.empty()){
            int t = q.front() ;
            q.pop() ;
            
            res.push_back(t) ;
            count++ ;
            
            for(int nbr : graph[t]){
                indegree[nbr]-- ;
                
                if(indegree[nbr] == 0)
                    q.push(nbr) ;
            }
            
            
        }
        
        return count == n ? res : vector<int>() ;
    }
};