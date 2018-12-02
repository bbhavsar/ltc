#include "common.hh"
// https://leetcode.com/problems/subdomain-visit-count/

vector<string> subdomainVisits(const vector<string>& cpdomains) {
    unordered_map<string, int> domain_count;
    for (auto s : cpdomains) {
        int split_idx  = s.find(' ');
        int count = stoi(s.substr(0, split_idx));
        string domain = s.substr(split_idx + 1);

        while (!domain.empty()) {
            domain_count[domain] += count;
            split_idx  = domain.find('.');
            if (split_idx == string::npos) {
                break;
            }
            domain = domain.substr(split_idx + 1);
        }
    }

    vector<string> result;
    result.reserve(domain_count.size());
    for (auto p : domain_count) {
        stringstream ss;
        ss << p.second << " " << p.first;
        result.emplace_back(ss.str());
    }
    return result;
}

int main() {
    vector<string> input =
     {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};

    for (auto s : subdomainVisits(input)) {
        cout << s << endl;
    }
    return 0;
}

