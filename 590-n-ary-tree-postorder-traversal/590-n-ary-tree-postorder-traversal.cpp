/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    
   
    void post(Node *node, vector<int>&ans)
    {
        if(node==NULL)
            return ;
        for(auto &n:node->children)
            post(n,ans);
        ans.push_back(node->val);
    }
    vector<int> postorder(Node* root) {
        
        vector<int>ans;
        post(root,ans);
        return ans;
    }
};