#include "common.hh"
#include <functional>

void releaseHydrogen() {
    cout << "H" << endl;;
}

void releaseOxygen() {
    cout << "O" << endl;
}

class H2O {
private:
    // acquisition count
    int Ha, Oa;
    // release count
    int Hr, Or;
    condition_variable cv;
    condition_variable cv_breached;
    mutex m;
    bool breached;

    void reset() {
        Ha -= 2;
        Oa--;
        Hr = 2;
        Or = 1;
        breached = false;
    }

public:
    H2O() {
        Ha = Oa = 0;
        Hr = 2;
        Or = 1;
        breached = false;
    }
    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lk(m);

        while (breached) {
            cv_breached.wait(lk);
        }

        Ha++;
        cout << "Hydrogen: Ha : " << Ha << " Oa: " << Oa << endl;
        if (Ha >= 2 && Oa >= 1) {
            // barrier breached
            // release H thread
            Hr--;
            breached = true;

            // releaseHydrogen() outputs "H". Do not change or remove this line.
            releaseHydrogen();

            lk.unlock();
            cv.notify_all();
        } else {
            while (Ha < 2 || Oa < 1 || Hr == 0) {
                cv.wait(lk);
            }
            Hr--;

            // releaseHydrogen() outputs "H". Do not change or remove this line.
            releaseHydrogen();

            if (Or == 0 && Hr == 0) {
                // all threads released
                reset();
                lk.unlock();
                cv_breached.notify_all();
            }
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lk(m);
        while (breached) {
            cv_breached.wait(lk);
        }

        Oa++;
        cout << "Oxygen: Ha : " << Ha << " Oa: " << Oa << endl;
        if (Ha >= 2 && Oa >= 1) {
            // barrier breached
            // release O thread
            Or--;
            breached = true;

            // releaseOxygen() outputs "O". Do not change or remove this line.
            releaseOxygen();

            lk.unlock();
            cv.notify_all();
        } else {
            while (Ha < 2 || Oa < 1 || Or == 0) {
                cv.wait(lk);
            }
            Or--;

            // releaseOxygen() outputs "O". Do not change or remove this line.
            releaseOxygen();

            if (Or == 0 && Hr == 0) {
                // all threads released
                reset();
                lk.unlock();
                cv_breached.notify_all();
            }
        }
    }
};

int main() {
    H2O w;
    string s = "OOHHHH";
    vector<thread> tids;
    for (char c : s) {
        if (c == 'H') {
            tids.push_back(thread(&H2O::hydrogen, &w, releaseHydrogen));
        } else {
            tids.push_back(thread(&H2O::oxygen, &w, releaseOxygen));
        }
    }
    for (thread &t : tids) {
        t.join();
    }

    return 0;
}

