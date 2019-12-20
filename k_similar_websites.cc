
#include "common.hh"

struct WebsitePairScore {
    string a, b;
    double score;
    WebsitePairScore(string a, string b, double score) : a(a), b(b), score(score) {}
    bool operator<(const WebsitePairScore& rhs) const {
        return score < rhs.score;
    }
};

double score(const set<int>& users1, const set<int>& users2) {
    vector<int> u;
    set_union(users1.begin(), users1.end(), users2.begin(), users2.end(), back_inserter(u));
    auto num_u = u.size();

    vector<int> in;
    set_intersection(users1.begin(), users1.end(), users2.begin(), users2.end(), back_inserter(in));
    auto num_i = in.size();

    return (double)num_i / (double)num_u;
}

vector< pair<string, string> > similarWebsites(const vector<pair<string, int> >& website_user,
                                               int k) {
    unordered_map<string, set<int> > website_users;

    for (auto p : website_user) {
        website_users[p.first].insert(p.second);
    }
    vector<string> websites;
    websites.reserve(website_users.size());
    for (auto p : website_users) {
        websites.emplace_back(p.first);
    }

    priority_queue<WebsitePairScore> max_heap;
    for (int i = 0; i < websites.size() - 1; i++) {
        for (int j = i + 1; j < websites.size(); j++) {
            double sc = score(website_users[websites[i]], website_users[websites[j]]);
            max_heap.emplace(websites[i], websites[j], sc);
        }
    }

    vector< pair< string, string> > result;
    while (!max_heap.empty() && k-- > 0) {
        auto wbs = max_heap.top();
        result.emplace_back(wbs.a, wbs.b);
        max_heap.pop();
    }

    return result;
}

int main() {
    vector< pair<string, int> > website_user = {
        {"a", 1}, {"a", 3}, {"a", 5},
        {"b", 2}, {"b", 6},
        {"c", 1}, {"c", 2}, {"c", 3}, {"c", 4}, {"c", 5},
        {"d", 4}, {"d", 5}, {"d", 6}, {"d", 7},
        {"e", 1}, {"e", 3}, {"e", 5}, {"e", 6}

    };

    for (auto p : similarWebsites(website_user, 1)) {
        cout << p.first << "," << p.second << endl;
    }

    return 0;
}

