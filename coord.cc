#include "common.hh"

class Coord {
private:
    mutex m;
    condition_variable cv1, cv2;
    bool first_done;
    bool second_done;

public:
    Coord() : first_done(false), second_done(false) {}
    void first() {
        unique_lock<mutex> lk(m);

        assert(!first_done);
        cout << "1" << endl;
        first_done = true;
        cv1.notify_one();
    }

    void second() {
        unique_lock<mutex> lk(m);

        assert(!second_done);
        while (!first_done) {
            cv1.wait(lk);
        }

        cout << "2" << endl;
        second_done = true;
        cv2.notify_one();
    }

    void third() {
        unique_lock<mutex> lk(m);

        while (!second_done) {
            cv2.wait(lk);
        }
        cout << "3" << endl;
    }
};


int main() {
    Coord c;

    thread t1(&Coord::third, &c);
    thread t2(&Coord::second, &c);
    thread t3(&Coord::first, &c);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}

