class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& Neww){
        if (node == NULL){
            return NULL;
        }
        if (Neww.count(node)){
            return Neww[node];
        }
        Node* clone = new Node(node->val);
        Neww[node] = clone;
        
        for (Node* n : node->neighbors){
            clone->neighbors.push_back(dfs(n,Neww));
        }
        return clone;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> Neww;
        return dfs(node,Neww);
    }
};
