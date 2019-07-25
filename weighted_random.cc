#include "common.hh"

class WeightedRandom {
private:
  // key is population count range and value is the city
  map<int, string> pop_city;
  int pop_count;
public:
  WeightedRandom(const unordered_map<string, int>& city_pop) : pop_count(0) {
    for (auto p : city_pop) {
      if (p.second == 0) {
        continue;
      }
      pop_count += p.second;
      pop_city[pop_count-1] = p.first;
    }
    srand(time(NULL));
  }

  string random_city() {
    int rand_idx = rand() % pop_count;
    auto it = pop_city.lower_bound(rand_idx);
    return it->second;
  }
};

int main() {
  unordered_map<string, int> city_pop = {
    {"Mumbai", 1000},
    {"Shanghai", 48},
    {"Sao Paolo", 700},
    {"New York", 200},
    {"Vatican", 2}
  };

  WeightedRandom wr(city_pop);

  for (int i = 0; i < 10; i++) {
    cout << wr.random_city() << endl;
  }
  return 0;
}


