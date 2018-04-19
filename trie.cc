#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

static const int BRANCH_FACTOR = 26;

struct Node {
    struct Node* arr[BRANCH_FACTOR];
    char c;
    bool isWord;
    Node(char ch) : isWord(false), c(ch)  {
        for (int i = 0; i < BRANCH_FACTOR; i++) {
            arr[i] = NULL;
        }
    }
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node('R');
    }

    void deleteRecurse(Node *curr) {
        for (int i = 0; i < BRANCH_FACTOR; i++) {
            if (curr->arr[i] != NULL) {
                deleteRecurse(curr->arr[i]);
                delete curr->arr[i];
                curr->arr[i] = NULL;
            }
        }
    }

    ~Trie() {
        if (root != NULL) {
            deleteRecurse(root);
        }
    }

    void insert(const string& s) {
        Node *curr = root;
        for (const char c : s) {
            assert(c >= 'a' && c <= 'z');
            int idx = c - 'a';
            assert(curr != NULL);
            if (curr->arr[idx] == NULL) {
                Node *n = new Node(c);
                curr->arr[idx] = n;
            }
            curr = curr->arr[idx];
        }
        curr->isWord = true;
    }

    bool search(const string& s) {
        Node *curr = root;
        for (const char c : s) {
            assert(c >= 'a' && c <= 'z');
            int idx = c - 'a';
            assert(curr != NULL);
            if (curr->arr[idx] == NULL) {
                return false;
            }
            assert(curr->arr[idx]->c == c);
            curr = curr->arr[idx];
        }
        return true;
    }

};

int main() {
    string strs[] = {"foo", "bar", "baz"};
    Trie t;
    for (string& s : strs) {
        t.insert(s);
    }
    cout << t.search("bara") << endl;
    cout << t.search("baz") << endl;
    cout << t.search("foo") << endl;
    cout << t.search("bara") << endl;

    return 0;
}

