#include "common.hh"


vector<string> fullJustify(vector<string>& words, const int maxWidth) {
    vector<string> result;
    for (int i = 0; i < words.size();) {
        vector<string> line;
        int line_len = 0;
        bool reached_max_line = false;
        while (!reached_max_line && i < words.size()) {
            if (line_len + line.size()  + words[i].length() <= maxWidth) {
                line.push_back(words[i]);
                line_len += words[i].length();
                i++;
            } else {
                reached_max_line = true;
            }
        }
        bool last_line = i == words.size();
        stringstream line_str;
        if (!last_line) {
            int remaining_spaces = maxWidth - (line_len + line.size() - 1);
            int num_words = line.size() - 1;
            int extra_spaces_per_word = remaining_spaces - 1;
            int remainder_spaces_after_padding = 0;
            if (num_words != 0) {
                extra_spaces_per_word = remaining_spaces / num_words;
                remainder_spaces_after_padding = remaining_spaces % num_words;
            }
            string extra_spaces;
            if (extra_spaces_per_word > 0) {
                extra_spaces = string(extra_spaces_per_word, ' ');
            }
            for (int j = 0; j < line.size(); j++) {
                line_str << line[j];
                if (j == 0 || j != line.size()-1) {
                    line_str << " ";
                    if (extra_spaces_per_word > 0) {
                        line_str << extra_spaces;
                    }
                    if (remainder_spaces_after_padding > 0) {
                        line_str << " ";
                        remainder_spaces_after_padding--;
                    }
                }
            }
        } else {
            for (int j = 0; j < line.size(); j++) {
                line_str << line[j];
                if (j != line.size()-1) {
                    line_str << " ";
                }
            }
            int remainder = maxWidth - line_str.str().length();
            while (remainder-- > 0) {
                line_str << " ";
            }
        }
        cout << line_str.str() << endl;
        assert(line_str.str().length() == maxWidth);
        result.push_back(line_str.str());
    }

    return result;
}

int main() {
    /*
    vector<string> text = {"This", "is", "an", "example", "of", "text", "justification."};
    for (auto s : fullJustify(text, 16)) {
        cout << "'" << s << "'" << endl;
    }
    cout << endl;

    vector<string> text1 = {"What","must","be","acknowledgment","shall","be"};
    for (auto s : fullJustify(text1, 16)) {
        cout << "'" << s << "'" << endl;
    }
    cout << endl;

    vector<string> text2 = {"Science","is","what","we","understand","well","enough","to","explain", "to","a","computer.","Art","is","everything","else","we","do" };
    for (auto s : fullJustify(text2, 20)) {
        cout << "'" << s << "'" << endl;
    }
    cout << endl;
    */

    vector<string> text3 = {"Listen","to","many,","speak","to","a","few."};
    for (auto s : fullJustify(text3, 6)) {
        cout << "'" << s << "'" << endl;
    }
    cout << endl;

    return 0;
}

