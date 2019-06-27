#include <vector>
#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

struct Result {
    vector<int> path;
    double value;
};


struct State {
    int vertex;
    vector<int> path;
    double curr_val;
    State(int v, vector<int> p, double c) : vertex(v), path(p), curr_val(c) {}
};


Result convertCurrency(int src, int dst,
                        vector< vector<double> > prices) {
    queue<State> q;
    vector<int> v = {src};
    q.push(State(src, v, 1.0));

    double max_val = -1;
    vector<int> max_path;
    while (!q.empty()) {
        auto elem = q.front();
        q.pop();
        int u = elem.vertex;
        cout << "Analyzing " << u << endl;
        double curr_value = elem.curr_val;
        for (int v = 0; v < prices[u].size(); v++) {
            if (u == v) {
                continue;
            }
            if (fabs(prices[u][v] + 1.0) < 0.000001) {
                continue;
            }
            bool vInPath = false;
            for (auto p : elem.path) {
                if (p == v) {
                    vInPath = true;
                }
            }
            if (vInPath) {
                continue;
            }

            auto target_val = curr_value * prices[u][v];
            auto new_path = elem.path;
            new_path.push_back(v);
            if (v == dst) {
                if (target_val > max_val) {
                    max_val = target_val;
                    max_path = new_path;
                }
            } else {
                q.push(State(v, new_path, target_val));
            }
        }
    }

    Result r;
    r.value = max_val;
    r.path = max_path;

    return r;
}

int main() {
    vector< vector<double> > prices = {
        //         BTC, USD, ETH, EUR
        // BTC
                  {1.0,  12000, -1.0, -1.0},
        // USD
                  {1.0/12500.0, 1.0, 1.0/310.0, 0.001},
        // ETH
                 {-1.0, 280, 1.0, 200.0},

        // EUR
                {-1.0, 1.0/0.9, 1.0/220.0, 1.0}

    };

    auto r = convertCurrency(0, 3, prices);
    cout << "Value: " << r.value << endl;
    for (auto p : r.path) {
        cout << p << " ";
    }
    cout << endl;


    return 0;
}


