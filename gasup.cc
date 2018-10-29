#include "common.hh"

const int mpg = 20;

int gasup(const vector<int>& gas, const vector<int>& cost) {
    assert(gas.size() == cost.size());
    int remaining_gallons = 0;
    int min_city = -1;
    int min_gallons = INT_MAX;

    const int num_cities = gas.size();
    int sum_gas = 0;
    int sum_cost = 0;
    for (int i = 0; i < num_cities; i++) {
        sum_gas += gas[i];
        sum_cost += cost[i] / mpg;
        remaining_gallons += gas[i] - cost[i] / mpg;
        if (remaining_gallons < min_gallons) {
            min_city = i + 1;
            min_gallons = remaining_gallons;
        }
    }

    return sum_gas >= sum_cost ? min_city % num_cities : -1;
}

int main() {
    vector<int> gas = { 50, 20, 5, 30, 25, 10, 15 };
    vector<int> cost = {900, 600, 200, 400, 600, 200, 100};

    cout << gasup(gas, cost) << endl;

    return 0;
}

