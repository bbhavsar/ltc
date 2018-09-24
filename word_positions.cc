#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class WordPositions {
    void convertToLower(string& s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    }
public:
    WordPositions(const string& file_path) {
        vector<string> words = read_file_to_words(file_path);
        for (int i = 0; i < words.size(); i++) {
            convertToLower(words[i]);
            word_positions[words[i]].push_back(i);
        }
    }

    vector<int> get_positions(const string& word) {
        string lword = word;
        convertToLower(lword);
        auto it = word_positions.find(lword);
        if (it != word_positions.end()) {
            return it->second;
        }
        return vector<int>();
    }

private:
    unordered_map<string, vector<int> > word_positions;

    vector<string> read_ss_to_words(stringstream& ss) {
        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }

    vector<string> read_file_to_words(const string& file_path) {
        ifstream f(file_path);
        stringstream ss;
        vector<string> words;
        if (f.is_open()) {
            ss << f.rdbuf();
            words = read_ss_to_words(ss);
            f.close();
        }
        return words;
    }
};

int main() {
    WordPositions wp("/tmp/h.txt");
    string words[] = {"Hello", "World", "haha", };
    for (auto word : words) {
        cout << word << ":";
        for (int pos : wp.get_positions(word)) {
            cout << pos << " ";
        }
        cout << endl;
    }
    return 0;
}

