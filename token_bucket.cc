#include "common.hh"
#include "time.h"

class TokenBucketThrottler {
private:
    const int maxBucketSize;
    int currentBucketSize;
    int fillRatePerSecond;
    int lastFillTimeStamp;

    void refill() {
        const int now = time(0);
        int intervalSinceLastRefill = now - lastFillTimeStamp;
        int additionalTokens = intervalSinceLastRefill * fillRatePerSecond;

        currentBucketSize = min(maxBucketSize, currentBucketSize + additionalTokens);
        lastFillTimeStamp = now;
    }

public:
    TokenBucketThrottler(int maxSize, int rate) : maxBucketSize(maxSize),
        fillRatePerSecond(rate), currentBucketSize(maxBucketSize),
        lastFillTimeStamp(time(0)) {}

    bool okayToAccept(int tokens=1) {
        refill();

        if (tokens >= currentBucketSize) {
           currentBucketSize -= tokens;
            return true;
        }

        return false;
    }
};


int main() {

    return 0;
}

