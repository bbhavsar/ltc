#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class WordTransform {
private:
    unordered_map<string, vector<string> > graph;
    unordered_set<string> dict;

    void construct_graph() {
        for (const string& word : dict) {
            for (int i = 0; i < word.length(); ++i) {
                // remove char
                string r = word;
                r.erase(i, 1);
                if (dict.count(r) != 0) {
                    // cout << "remove:" << word << ":" << r << endl;
                    graph[word].push_back(r);
                }
                for (char c = 'a'; c <= 'z'; c++) {
                    // change char
                    string s = word;
                    s[i] = c;
                    if (s != word && dict.count(s) != 0) {
                        // cout << "change:" << word << ":" << s << endl;
                        graph[word].push_back(s);
                    }
                }
            }
            for (int i = 0; i <= word.length(); ++i) {
                string left = word.substr(0, i);
                string right = word.substr(i);
                for (char c = 'a'; c <= 'z'; c++) {
                    // add char
                    string a = left + c + right;
                    if (dict.count(a) != 0) {
                        // cout << "add:" << word << ":" << a << endl;
                        graph[word].push_back(a);
                    }
                }
            }

            auto it = graph.find(word);
            if (it == graph.end()) {
                graph.insert(make_pair(word, vector<string>()));
            }
        }
    }

public:
    WordTransform(const vector<string>& in_dict) {
        for (string word : in_dict) {
          transform(word.begin(), word.end(), word.begin(), ::tolower);
          dict.insert(word);
        }
        construct_graph();
    }

    void print_graph() {
        for (const auto& p : graph) {
            cout << p.first << ":";
            for (const auto& s : p.second) {
                cout << s << " ";
            }
            cout << endl;
        }
    }

    vector<string> transform_src_dst(const string& src, const string& dst) {
      vector<string> result;
      // src word doesn't exist in dictionary.
      if (dict.count(src) == 0) {
        return result;

      }
      unordered_set<string> visited;
      unordered_map<string, string> rev_map;
      list<string> q;
      q.push_back(src);
      string u;
      while (!q.empty()) {
        u = q.front();
        q.pop_front();
        if (u == dst) {
          break;
        }
        for (auto v : graph[u]) {
          if (visited.count(v) == 0) {
            visited.insert(v);
            q.push_back(v);
            rev_map.insert(make_pair(v, u));
          }
        }
      }

      if (u == dst) {
        string curr = dst;
        while (curr != src) {
          result.push_back(curr);
          curr = rev_map[curr];
        }
        result.push_back(curr);
        reverse(result.begin(), result.end());
      }

      return result;
    }
};

void transform_helper(WordTransform& wt, const string& src, const string& dst) {
    vector<string> result = wt.transform_src_dst(src, dst);
    for (auto s : result) {
      cout << s << " ";
    }
    cout << endl;
}


int main() {
    vector<string> words = {"hi", "hello", "ola", "hit", "he", "hell", "ol", "hits", "cola", "colas"};
    WordTransform wt(words);
    // wt.print_graph();

    pair<string, string> pairs[] = { make_pair("he", "hits"), make_pair("hell", "hello"),
      make_pair("colas", "ol")};

    for (auto p : pairs) {
      transform_helper(wt, p.first, p.second);
    }

    return 0;
}


