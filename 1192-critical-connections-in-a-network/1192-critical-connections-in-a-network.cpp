class Solution {
public:
    int dfs(vector<vector<int>>& graph, int start, int rank, vector<int>& visited, vector<vector<int>> &res) {
        
        visited[start] = rank;
        
        int t = INT_MAX, rv = INT_MAX;
        for(auto &nbr : graph[start]) {
            if(!visited[nbr]) {
                t = dfs(graph, nbr, rank+1, visited, res);
                
                if(t > rank)
                    res.push_back({start, nbr});
            
            }
            // Back-edge
            else {
                if(rank > visited[nbr]+1)
                    t = visited[nbr];
            }
            
            rv = min(rv, t);
        }
        
        visited[start] = graph.size()+1;
        
        return rv;
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Construct the graph
        vector<vector<int>> graph(n);
        vector<int> visited(n, 0);
        vector<vector<int>> res;
        
        for(int i = 0; i < connections.size(); i++) {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        
        // Ready to do a DFS
        int t = dfs(graph, 0, 1, visited, res);
        
        return res;
        
    }
};