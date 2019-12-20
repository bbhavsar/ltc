
#include "common.hh"

class NestedInteger {
    private:
        int elem;
        vector<NestedInteger> l;
        NestedInteger();
    public:
        NestedInteger(int num) : elem(num) {}
        NestedInteger(const vector<NestedInteger>& v) {
            assert(!v.empty());
            l = v;
        }
   public:
     
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const {
        return l.empty();
     }

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const {
        return elem;
     }

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const {
        return l;
    }
 };


void flatten(NestedInteger ni, vector<int>& result);

void flatten(const vector<NestedInteger>& v, vector<int>& result) {
    for (auto ni : v) {
        flatten(ni, result);
    }
}

void flatten(NestedInteger ni, vector<int>& result) {
    if (ni.isInteger()) {
        result.push_back(ni.getInteger());
    } else {
        flatten(ni.getList(), result);
    }
}

class NestedIterator2 {
private:
    const vector<NestedInteger>& nl;
    vector<int> curr_list;
    int curr_idx = 0;
    int nl_idx = 0;
public:
    NestedIterator2(const vector<NestedInteger> &nestedList) : nl(nestedList) {
    }

    int next() {
        return curr_list[curr_idx++];
    }

    bool hasNext() {
        if (curr_idx < curr_list.size()) {
            return true;
        }
        curr_list.clear();
        curr_idx = 0;
        while (curr_list.empty() && nl_idx < nl.size()) {
            flatten(nl[nl_idx++], curr_list);
        }
        return curr_idx < curr_list.size();
    }
};


class NestedIterator {
private:
    vector<int> l;
    int i = 0;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList, l);
    }

    int next() {
        return l[i++];
    }

    bool hasNext() {
        return i < l.size();
    }
};


int main() {
    NestedInteger ni(1);
    vector<NestedInteger> v;
    v.push_back(NestedInteger(2));
    v.push_back(NestedInteger(3));
    v.push_back(NestedInteger(v));

    vector<int> result;
    flatten(v, result);

    for (auto elem : result) {
        cout << elem << " ";
    }
    cout << endl;

    NestedIterator2 nit(v);
    while (nit.hasNext()) {
        cout << nit.next() << endl;
    }

    return 0;

}



