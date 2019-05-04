
#include "common.hh"

// Implement algorithm for splitwise minimizing transactions among friends

struct Txn {
    int payer, receiver;
    double amount;
    Txn(int p, int r, double a) : payer(p), receiver(r), amount(a) {}
};

class SplitWise {
private:
    int num_friends;
    vector< vector<double> > credit_mat;

    bool doubleCompare(double lhs, double rhs) {
        static const double epsilon = 0.01;
        return abs(lhs - rhs) < epsilon;
    }
    void minTxnsRecur(vector<double>& credit_person, vector<Txn>& result) {
        auto max_credit = max_element(credit_person.begin(), credit_person.end());
        auto min_debit = min_element(credit_person.begin(), credit_person.end());

        assert(*max_credit >= 0);
        assert(*min_debit <= 0);
        if (doubleCompare(*max_credit, 0) && doubleCompare(*min_debit,0)) {
            return;
        }

        auto max_credit_idx = distance(credit_person.begin(), max_credit);
        auto min_debit_idx = distance(credit_person.begin(), min_debit);

        auto min_val = min(*max_credit, abs(*min_debit));
        if (min_val == *max_credit) {
            result.emplace_back(min_debit_idx, max_credit_idx, *max_credit);
            *min_debit += *max_credit;
            *max_credit = 0;
        } else {
            result.emplace_back(min_debit_idx, max_credit_idx, *min_debit);
            *max_credit -= *min_debit;
            *min_debit = 0;
        }
        return minTxnsRecur(credit_person, result);
    }

public:
    SplitWise(int n) : num_friends(n),
                       credit_mat(vector< vector<double> >(n, vector<double>(n, 0))) {}

    void addEvenPayment(int payer, double amount) {
        assert(payer < num_friends);
        double per_person_share = amount / (double)num_friends;
        for (auto i = 0; i < num_friends; i++) {
            credit_mat[payer][i] = per_person_share;
        }
    }

    void addTxn(const Txn& t) {
        assert(t.amount >= 0);
        assert(t.payer >= 0 && t.payer < num_friends && t.receiver >= 0 &&
               t.receiver < num_friends);
        credit_mat[t.payer][t.receiver] = t.amount;
    }

    vector<Txn> minimizeTxns(void) {
        vector<Txn> result;
        if (credit_mat.empty()) {
            return result;
        }

        // This must be a square matrix to cover debit for all friends.
        assert(credit_mat.size() == credit_mat[0].size());

        vector<double> credit_person(num_friends, 0);
        for (auto i = 0; i < num_friends; i++) {
            for (auto j = 0; j < num_friends; j++) {
                credit_person[i] += credit_mat[i][j] - credit_mat[j][i];
            }
        }

        minTxnsRecur(credit_person, result);
        return result;
    }
};


int main() {
    SplitWise sw(3);
    sw.addTxn(Txn(0, 1, 15));
    sw.addTxn(Txn(1, 2, 3));
    sw.addTxn(Txn(2, 1, 10));
    sw.addEvenPayment(1, 6);

    auto result = sw.minimizeTxns();
    for (auto t : result) {
        cout << t.payer << " pays " << t.receiver << " $" << t.amount << endl;
    }

    return 0;
}

