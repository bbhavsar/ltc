#include "common.hh"
#include "time.h"

struct Item {
    const int timestampSec;
    int counter;
    Item() : timestampSec(0), counter(0) {}
    Item(int ts) : timestampSec(ts), counter(1) {}
};

class FixedSizeWindow {
private:
    int requestRatePerMin;
    list<Item> l;
public:
    FixedSizeWindow(int rate) : requestRatePerMin(rate) {}

    bool isAllowed() {
        const int now = time(0);
        auto it = l.begin();
        int oldTs = now - 60;
        for (auto it = l.begin(); it != l.end(); ) {
            if (it->timestampSec <= oldTs) {
                it = l.erase(it);
            } else {
                break;
            }
        }
        int cumul = 0;
        for (const auto& item : l) {
            cumul += item.counter;
        }
        if (cumul >= requestRatePerMin) {
            return false;
        } else {
            if (!l.empty() && l.back().timestampSec == now) {
                l.back().counter++;
            } else {
                l.push_back(Item(now));
            }
            return true;
        }
    }
};

int main() {

    return 0;
}

