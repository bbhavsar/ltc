/*
https://leetcode.com/problems/k-closest-points-to-origin/


*/

#include "common.hh"

struct PointDistance {
    int dist;
    int idx;
    PointDistance(int d, int i) : dist(d), idx(i) {}
};

struct Compare {
    bool operator()(const PointDistance& lhs, const PointDistance& rhs) const {
        return lhs.dist < rhs.dist;
    }
};

int distance(const vector<int>& point) {
    int sqr_sum = 0;
    for (int dim : point) {
        sqr_sum += (dim * dim);
    }
    return sqr_sum;
}

vector< vector<int> > kClosest(const vector<vector<int>>& points, int K) {
    priority_queue<PointDistance, vector<PointDistance>, Compare> max_heap;
    int i = 0;
    for (; i < K && i < points.size(); i++) {
        max_heap.emplace(distance(points[i]), i);
    }

    for (; i < points.size(); i++) {
        int curr_dist = distance(points[i]);
        assert(!max_heap.empty());
        int max_distance = max_heap.top().dist;
        if (curr_dist < max_distance) {
            max_heap.pop();
            max_heap.emplace(curr_dist, i);
        }
        assert(max_heap.size() == K);
    }
    vector< vector<int> > result;
    while (!max_heap.empty()) {
        auto pd = max_heap.top();
        result.emplace_back(points[pd.idx]);
        max_heap.pop();
    }

    return result;
}

void printResult(const vector< vector<int> >& points, int K) {
    for (auto v : kClosest(points, K)) {
        cout << " [ ";
        for (auto dim : v) {
            cout << dim << " ";
        }
        cout << " ] ";
    }
    cout << endl;
}


int main() {
    vector< vector<int> > points = { {1, 3}, {-2, 2} };
    printResult(points, 1);

    vector< vector<int> > points2 = {{3,3},{5,-1},{-2,4}};
    printResult(points2, 2); 

    return 0;
}


