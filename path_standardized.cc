
/*

Given an absolute pathname that may have . or .. as part of it,i
return the shortest standardized path.

For example, given "/usr/bin/../bin/./scripts/../", return "/usr/bin/".
*/

#include "common.hh"

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/join.hpp>

string standardized_path(const string& p) {
    vector<string> elems;
    boost::algorithm::split(elems, p, boost::is_any_of("/"));

    vector<string> result;
    for (auto elem : elems) {
        if (elem != "." && elem != "..") {
            result.push_back(elem);
        } else if (elem == "..") {
            result.pop_back();
        }
    }

    return boost::algorithm::join(result, "/");
}


int main() {
    cout << standardized_path("/usr/bin/../bin/./scripts/../") << endl;

    return 0;
}

