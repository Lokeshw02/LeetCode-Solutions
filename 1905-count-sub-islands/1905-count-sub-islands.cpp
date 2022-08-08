class Solution {
public:
   void DFS(int i ,int j ,vector<vector<int>>& g1, vector<vector<int>>& g2,vector<vector<bool>>& vis,int &res)
    
    {
        if(i<0 ||  i>=g1.size() || j<0 || j>= g1[0].size()) return ;
        
        if(vis[i][j] || g2[i][j]==0) return ;
        
        if((g2[i][j] == 1 && g1[i][j] == 0) || (g2[i][j] == 0 && g1[i][j] == 1)) {
            res = 0 ;
        }
        
        vis[i][j] = true ;
        
        DFS(i+1,j,g1,g2,vis,res);
        DFS(i-1,j,g1,g2,vis,res);
        DFS(i,j-1,g1,g2,vis,res);
        DFS(i,j+1,g1,g2,vis,res);
        
        
    
    }
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        
     int n = g1.size();
     int m  = g1[0].size();
     int ans  = 0;
     vector<vector<bool>>vis(n,vector<bool>(m,false));
     for(int i  = 0;i<n;i++)
     {
         for(int j  = 0;j<m;j++)
         {
             if(g2[i][j] == 1 && !vis[i][j])
             {
                 int res = 1;
                 DFS(i,j,g1,g2,vis,res);
                 ans+=res;
                 
             }
             
             
         }
     }
        
        return ans;
        
        
        
    }
};