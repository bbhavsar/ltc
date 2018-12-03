/*
Given a chemical formula (given as a string), return the count of each atom.

An atomic element always starts with an uppercase character, then zero or more lowercase
letters, representing the name.

1 or more digits representing the count of that element may follow if the count is greater
than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible,
but H1O2 is impossible.

Two formulas concatenated together produce another formula. For example, H2O2He3Mg4
 is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula.
For example, (H2O2) and (H2O2)3 are formulas.
*/

#include "common.hh"

int getCount(const string& formula, int& i) {
	int count = 0;
	while (i < formula.length() && isdigit(formula[i])) {
		count = count * 10 + (formula[i++] - '0');
	}

	return count == 0 ? 1 : count;
}

string countOfAtoms(string formula) {
    map<string, int> atom_count;
    list< pair<string, int> > st;
    for (int i = 0; i < formula.length();) {
        if (isupper(formula[i])) {
            string atom = string(1, formula[i++]);
            if (i < formula.length() && islower(formula[i])) {
                atom += formula[i++];
            }
            int count = getCount(formula, i);
            if (st.empty()) {
                atom_count[atom] += count;
            } else {
                st.push_back(make_pair(atom, count));
            }
        } else if (formula[i] == '(') {
            i++;
            st.push_back(make_pair(string(1, '('), -1));
        } else if (formula[i] == ')') {
            i++;
            int count = getCount(formula, i);
            auto it = st.rbegin();
            for (; it != st.rend(); ++it) {
                if (it->first == "(") {
                    break;
                }
                it->second *= count;
                cout << it->first << " " << it->second << endl;
            }
            ++it;
            if (it == st.rend()) {
                // dump all members to map
                for (it = st.rbegin(); it != st.rend(); ++it) {
                    if (it->first == "(") {
                        break;
                    }
                    atom_count[it->first] += it->second;
                }
                st.clear();
            } else {
                // remove '('
                st.erase(it.base());
            }
        }
    }

    stringstream ss;
    for (auto p : atom_count) {
        ss << p.first;
        if (p.second != 1) {
            ss << p.second;
        }
    }

    return ss.str();
}


int main() {
    vector<string> input = {"Mg(OH)2", "K4(ON(SO3)2)2" };
    for (auto s : input) {
        cout << countOfAtoms(s) << endl;
    }
    return 0;
}

