class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //Create the Explicit Graph 
        vector<vector<int>>graph(numCourses) ;
        vector<int> in(numCourses,0) ;
        
        for(auto &pre : prerequisites ){
            graph[pre[1]].push_back(pre[0]) ;
            in[pre[0]]++ ;
        }
        //Push all the ) degree Nodes in the Queue 
        queue<int>q; 
        
        for(int i = 0; i < in.size(); i++){
            if(in[i] == 0 )
                q.push(i) ;
        }
        vector<int>res ;
        int count = 0 ;
        
        while(!q.empty()){
            int t = q.front() ;
            q.pop() ;
            
            count++ ;
            res.push_back(t) ;
            
            //Decreease the Indegrees of all the Adjecent Nodes 
            
            for(auto &nbr : graph[t]){
                in[nbr]-- ;
                if(in[nbr] == 0) 
                q.push(nbr) ;
                
            }
        }
        
        return count == numCourses ? res : vector<int>() ;
    }
};