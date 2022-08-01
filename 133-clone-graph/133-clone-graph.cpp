/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* dfs(Node* n, unordered_map<Node*,Node*> &m){
        Node * newN = new Node(n->val) ;
        
        m[n] = newN ;
        
        //Go through the unvisited Neighbours 
        
        for(auto &nbr : n->neighbors){
            if(m.find(nbr) == m.end()){
                 Node * n2 = dfs(nbr,m) ;
                newN->neighbors.push_back(n2) ;
            }
            else{
                newN->neighbors.push_back(m[nbr]) ;
            }
            
        }
        
        return newN ;
    }
    
    
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL ;
        unordered_map<Node*,Node*> m ;
        
        return dfs(node,m) ;
    }
};