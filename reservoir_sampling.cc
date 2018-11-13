#include "common.hh"

// https://stackoverflow.com/a/10984975
int get_random_range_mod(int low, int high) {
    int n = high - low + 1;

    int non_uniform_range = RAND_MAX - (RAND_MAX % n);
    int random;
    do {
        random = rand();
    } while (random >= non_uniform_range);

    random %= n;
    return low + random;
}

// https://en.wikipedia.org/wiki/Reservoir_sampling#Algorithm_R
class ReservoirSampling {
private:
    const int k;
    int num_elems;
    vector<int> elems;
public:
    ReservoirSampling(int size) : k(size), num_elems(0) {
        elems.reserve(k);
        srand(time(NULL));
    }

    void add_elem(int elem) {
        if (num_elems < k) {
            elems.push_back(elem);
            num_elems++;
            return;
        }

        int random = get_random_range_mod(0, num_elems - 1);
        if (random < k) {
            elems[random] = elem;
        }
        num_elems++;
    }

    int get_elem() {
        int random = get_random_range_mod(0, k - 1);
        return elems[random];
    }
};


int main() {


    return 0;
}

