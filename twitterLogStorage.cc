#include "common.hh"
// https://leetcode.com/problems/design-log-storage-system/

class LogSystem {
private:
    multimap<long, int> ids;
    long convertToTimestamp(const string& ts) {
        long year = (stoi(ts.substr(0, 4)) - 1999) * 12 * 30 * 24 * 60 * 60;
        long mon = (stoi(ts.substr(5, 2)) - 1) * 30 * 24 * 60 * 60;
        long day = stoi(ts.substr(8, 2)) * 24 * 60 * 60;
        long hr = stoi(ts.substr(11, 2)) * 60 * 60;
        long min = stoi(ts.substr(14, 2)) * 60;
        long sec = stoi(ts.substr(17, 2));
        return year + mon + day + hr + min + sec;
    }
    void getStartAndEndTime(string s, string e, const string& gra,
                            int *sts, int *ets) {
        static const unordered_map<string, vector<int> > mod_map = {
            { "Year", {0, 4, 5}, },
            { "Month", {5, 2, 8}, },
            { "Day", {8, 2, 11}, },
            { "Hour", {11, 2, 14}, },
            { "Minute", {14, 2, 17}, },
            { "Second", {17, 2, 19}, }
        };
        auto it = mod_map.find(gra);
        assert(it != mod_map.end());
        auto vec = it->second;
        fill(s.begin() + vec[2], s.end(), '0');
        *sts = convertToTimestamp(s);

        string plus_one = to_string(stoi(e.substr(vec[0], vec[1])) + 1);
        e.replace(vec[0], vec[1], plus_one);
        fill(e.begin() + vec[2], e.end(), '0');
        *ets = convertToTimestamp(e);
    }
public:
    void put(int id, string timestamp) {
       ids.emplace(convertToTimestamp(timestamp), id);
    }
    vector<int> retrieve(string s, string e, string gra) {
        int st, et;
        getStartAndEndTime(s, e, gra, &st, &et);
        vector<int> result;
        for (auto it = ids.lower_bound(st); it != ids.end(); ++it) {
            if (it->first >= et) {
                break;
            }
            result.emplace_back(it->second);
        }
        return result;
    }
};

int main() {
    LogSystem ls;

    ls.put(1, "2017:01:01:23:59:59");
    ls.put(2, "2017:01:01:22:59:59");
    ls.put(3, "2016:01:01:00:00:00");

    for (auto id : ls.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour")) {
        cout << id << " " << endl;
    }
    return 0;
}

