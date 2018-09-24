#include <iostream>
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
};

int main() {
    vector<string> words = {"hi", "hello", "ola", "hit", "he", "hell", "ol", "hits"};
    WordTransform wt(words);
    wt.print_graph();

    return 0;
}


