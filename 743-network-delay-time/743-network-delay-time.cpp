class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>> > graph(n+1) ;  
        vector<int> visited(n+1,false) ;
        
        for(auto time : times){
            graph[time[0]].push_back({time[1],time[2]}) ;
        }
        
        int res = -1 , count = 0 ;
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq ;
        //First as the Weight // Second as the Node Number 
        
        pq.push({0,k}) ;
        
        while(!pq.empty()){
            pair<int,int> t = pq.top() ;
            pq.pop() ;
            
            //Ignore already vissited Nodes 
            if(visited[t.second]) continue ;
            res = max(res, t.first) ;
            visited[t.second] = true ;
            count++ ;
            //Push the unvisited neighbours 
            
            for(auto &nbr : graph[t.second] ){
                if(!visited[nbr.first]){
                    pq.push({t.first+nbr.second, nbr.first}) ;
                }
            }
        }
        
        return count == n ? res : -1 ;
    }
};