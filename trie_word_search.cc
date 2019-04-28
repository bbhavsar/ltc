
#include "common.hh"

// https://leetcode.com/problems/add-and-search-word-data-structure-design/submissions/

struct TrieNode {
    char c;
    bool end;
    vector<TrieNode*> arr;
    TrieNode(char ch, bool is_end) : c(ch), end(is_end), arr(vector<TrieNode*>(26, NULL)) {}
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() : root(new TrieNode('-', false)) {}

    void add(string word) {
        TrieNode *curr = root;
        for (char c : word) {
            const int offset = c - 'a';
            if (curr->arr[offset] == NULL) {
                curr->arr[offset] = new TrieNode(c, false);
            }
            curr = curr->arr[offset];
        }
        assert(curr != NULL);
        curr->end = true;
    }

    bool search(TrieNode *curr, const string& word, int idx) {
        if (idx == word.length()) {
            return curr->end;
        }

        char c = word[idx];
        const int offset = c - 'a';
        if (c != '.') {
            if (curr->arr[offset] == NULL) {
                return false;
            } else {
                return search(curr->arr[offset], word, idx + 1);
            }
        } else {
            for (TrieNode* n : curr->arr) {
                if (n != NULL) {
                    if (search(n, word, idx + 1)) {
                        return true;
                    }
                }
            }
            return false;
        }
    }

    bool search(string word) {
        return search(root, word, 0);
    }
};

class WordDictionary {
private:
    Trie t;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        t.add(word);
    }
    /** Returns if the word is in the data structure. A word could contain the dot
        character '.' to represent any one letter. */
    bool search(string word) {
        return t.search(word);
    }
};

int main() {
    WordDictionary wd;
    vector<string> words = { "bad", "dad", "mad"};
    for (auto s : words) {
        wd.addWord(s);
    }
    vector<string> match =  { "pad", "bad", ".ad", "b.."};
    for (auto m : match) {
        cout << m << ": " << wd.search(m) << endl;
    }
    return 0;
}

