#include "common.hh"

int max_frequency_min_subarray(vector<int>& num) {
  unordered_map<int, vector<int> > freq;

  for (int i = 0; i < num.size(); i++) {
    freq[num[i]].emplace_back(i);
  }

  int max_freq = 0;
  vector<int> max_freq_elems;
  for (const auto& p : freq) {
    cout << p.first << "\t" << p.second.size() << endl;
    if (p.second.size() > max_freq) {
      max_freq_elems.clear();
      max_freq_elems.emplace_back(p.first);
      max_freq = p.second.size();
    } else if (p.second.size() == max_freq) {
      max_freq_elems.emplace_back(p.first);
    }
  }

  int min_dist = num.size();
  for (auto max_freq_elem : max_freq_elems) {
    cout << max_freq_elem << endl;
    auto dist = freq[max_freq_elem].back() - freq[max_freq_elem].front();
    if (dist < min_dist) {
      min_dist = dist;
    }
  }
  return min_dist;
}

int main() {
  vector<int> num = { 1, 2, 2, 1, 1, 1, 2, 2, 3, 3, 3, 3, 3};

  cout << max_frequency_min_subarray(num) << endl;

  return 0;
}

