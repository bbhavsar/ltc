// https://leetcode.com/problems/sentence-screen-fitting/

#include "common.hh"

int wordsTypingSlow(vector<string>& sentence, int rows, int cols) {
    int word_idx = 0;
    int result = 0;
    for (int row_idx = 0; row_idx < rows; row_idx++) {
        int space_left = cols;

        while (space_left > 0) {
            if (sentence[word_idx].length() > space_left) {
                break;
            }
            space_left -= sentence[word_idx].length();
            space_left--;
            word_idx++;
            if (word_idx == sentence.size()) {
                word_idx = 0;
                result++;
            }
        }
    }

    return result;
}

void computeIndices(const vector<string>& sentence, const int rows, const int cols,
                    int col_idx,
                    unordered_map<int, pair<int, int> >& cache) {
    int space_left = cols - col_idx;
    bool done = false;
    int word_idx = 0;
    for (int row_idx = 0; !done; row_idx++) {
        while (space_left > 0) {
            if (sentence[word_idx].length() > space_left) {
                break;
            }
            space_left -= sentence[word_idx].length();
            word_idx++;
            if (word_idx == sentence.size()) {
                cache[col_idx] = make_pair(row_idx, cols-space_left-1);
                // cout << col_idx << " " << row_idx << " " << cache[col_idx].second << endl;
                done = true;
                break;
            }
            space_left--;
        }
        space_left = cols;
    }
}

int wordsTyping(vector<string>& sentence, int rows, int cols) {
    int result = 0;
    unordered_map<int, pair<int, int> > cache;

    int row_idx = 0;
    int col_idx = 0;
    while (row_idx < rows) {
        auto it = cache.find(col_idx);
        if (it == cache.end()) {
            computeIndices(sentence, rows, cols, col_idx, cache);
            assert(cache.find(col_idx) != cache.end());
        }
        int end_row_idx = cache[col_idx].first + row_idx;
        int end_col_idx = cache[col_idx].second;
        // cout << end_row_idx << " " << end_col_idx << endl;
        if (end_row_idx < rows) {
            result++;
        } else {
            break;
        }
        int next_row_idx = end_row_idx;
        int next_col_idx = end_col_idx + 2;
        if (next_col_idx >= cols) {
            next_col_idx = 0;
            next_row_idx++;
        }
        row_idx = next_row_idx;
        col_idx = next_col_idx;
    }

    return result;
}



int main() {
    vector<string> words = { "hello", "world" };
    cout << wordsTyping(words, 2, 8) << endl;

    cout << "====" << endl;

    vector<string> words2 = {"a", "bcd", "e"};
    cout << wordsTyping(words2, 3, 6) << endl;

    cout << "====" << endl;

    vector<string> words3 = {"a"};
    cout << wordsTyping(words3, 1000, 1000) << endl;

    return 0;
}

