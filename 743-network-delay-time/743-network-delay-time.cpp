class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //Explicit graph Creation 
        //Adjecency List 
        vector<vector<pair<int,int>>>graph(n+1) ;
        vector<bool> visited(n+1, false) ;
        
        int res =-1, count = 0 ;
        
        for(auto &time : times){
            graph[time[0]].push_back({time[1],time[2]}) ;
            
        }
        //Weighted BFS 
        //Minimum Priority Quieue 
        //Evevry element is a pair <-- first as the weight , second is the node number 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq ;
        
        //Initialise 
        pq.push({0,k}) ;
        
        while(!pq.empty()){
            pair<int,int>t = pq.top() ;
            pq.pop() ;
            
            //Ignore already visited Nodes 
            
            if(visited[t.second]) continue ;
            
            //shortest path to this node has been computed 
            res = max(res, t.first) ;
            //Mark it as Visited 
            visited[t.second] = true ;
            count++ ;
            
            //Push its unvisited neighbours 
            for(auto &nbr : graph[t.second]){
                if(!visited[nbr.first]){
                    pq.push({t.first + nbr.second, nbr.first}) ;
                }
            }
            
        }
        
        return count  == n ? res : -1 ;
    }
};