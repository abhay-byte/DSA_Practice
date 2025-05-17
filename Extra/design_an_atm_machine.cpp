#include <vector>
using namespace std;

class ATM {
    vector<long long> notes;
    vector<int> values{20, 50, 100, 200, 500};

public:
    ATM() {
        notes = vector<long long>{0,0,0,0,0};
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i) {
            notes[i] += banknotesCount[i]; 
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> result(5, 0);
        for (int i = 4; i >= 0; --i) {
            long long canTake = min((long long)(amount / values[i]), notes[i]);
            result[i] = (int)canTake;
            amount -= canTake * values[i];
        }
        if (amount != 0) return {-1};
        for (int i = 0; i < 5; ++i) {
            notes[i] -= result[i];
        }
        return result;
    }
};
