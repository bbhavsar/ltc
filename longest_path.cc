#include "common.hh"

struct WordLen {
    string w;
    int sum_len;
    WordLen(const string& s, int len) : w(s), sum_len(len) {}
    WordLen() : w(string()), sum_len(0) {}
};

string construct_max_path(const list<WordLen>& l, const string& word) {
    stringstream ss;
    for (auto wl : l) {
        ss << wl.w << "/";
    }
    ss << word;
    return ss.str();
}

// 0, 1, 2, 3, n 

string longest_path(string& str) {
    const int length = str.length();

    list<WordLen> l;
    int max_path_len = 0;
    string max_path;
    int pos = 0;
    while (pos < length) {
        int end = str.find('\n', pos);
        string word;
        if (end != string::npos) {
            word = str.substr(pos, end - pos);
        } else {
            word = str.substr(pos);
        }
        int parent_path_len = l.empty() ? 0 : l.back().sum_len;
        if (max_path_len < parent_path_len + word.length()) {
            max_path_len = parent_path_len + word.length();
            max_path = construct_max_path(l, word);
        }

        if (end == string::npos) {
            break;
        }

        // Prepare for next word looking for tabs
        pos = end + 1;
        int levels = 0;
        for (; pos < length; pos++) {
            if (str[pos] == '\t') {
                levels++;
            } else {
                break;
            }
        }
        if (levels > l.size()) {
            assert(levels == l.size() + 1);
            int sum_len = l.empty() ? 0 : l.back().sum_len;
            sum_len += word.length();
            l.emplace_back(word, sum_len);
        } else {
            while (levels < l.size()) {
                l.pop_back();
            }
        }
    }

    return max_path;
}


int main () {
    vector<string> strs = {
        "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext",
        "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext",
        "dir\n\tsubdir\n\t\tabrakadabra.txt\nlongestParentDir" 
        };

    for (auto s : strs) {
        cout << longest_path(s) << endl;
    }

    return 0;
}

