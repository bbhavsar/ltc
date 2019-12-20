/*
https://leetcode.com/problems/course-schedule/
Course Schedule - https://leetcode.com/problems/course-schedule/
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take
 course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to
 finish all courses?

Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

*/

#include "common.hh"

class Graph {
public:
    unordered_map<int, vector<int> > adj_list;
    int num_vertices;

    Graph(int n) : num_vertices(n) {}
    void add_edge(int u, int v) {
        adj_list[u].push_back(v);
    }
};

class Solution {
private:
    bool dfs_util(int u, unordered_set<int>& visited, unordered_set<int>& rec_stack, Graph& g) {
        visited.insert(u);
        rec_stack.insert(u);

        for (auto v : g.adj_list[u]) {
            if (rec_stack.count(v) != 0) {
                return true;
            }
            if (visited.count(v) == 0) {
                bool cycle = dfs_util(v, visited, rec_stack, g);
                if (cycle) {
                    return true;
                }
            }
        }
        rec_stack.erase(u);
        return false;
    }

public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        Graph g(numCourses);
        for (auto p : prerequisites) {
            g.add_edge(p.first, p.second);
        }

        unordered_set<int> visited;
        unordered_set<int> rec_stack;
        for (int i = 0; i < numCourses; i++) {
            if (visited.count(i) == 0) {
                bool cycle = dfs_util(i, visited, rec_stack, g);
                if (cycle) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {

    return 0;
}

