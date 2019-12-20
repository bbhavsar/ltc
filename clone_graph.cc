/*
https://leetcode.com/problems/clone-graph/


*/

#include "common.hh"

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node *, Node *> map;
        queue<Node *> q;
        unordered_set<Node *> visited;

        Node *clone = new Node(node->val, vector<Node*>());
        q.push(node);
        map[node] = clone;
        while (!q.empty()) {
            Node *u = q.front();
            q.pop();
            assert(map.find(u) != map.end());
            Node *cloneu = map[u];
            for (auto v : u->neighbors) {
                auto it = map.find(v);
                Node *clonev = NULL;
                if (it == map.end()) {
                    clonev = new Node(v->val, vector<Node *>());
                    map[v] = clonev;
                } else {
                    clonev = it->second;
                }
                cloneu->neighbors.push_back(clonev);
                if (visited.count(v) == 0) {
                    q.push(v);
                }
            }
            visited.insert(u);
        }

        return clone;
    }
};

int main() {

    return 0;
}



