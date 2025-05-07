#include <iostream>
#include <vector>
using namespace std;

#include <vector>
using namespace std;

class Bank {
    vector<long> balance;
    int n;

public:
    Bank(vector<long>& balance) {
        this->balance = balance;
        n = balance.size();
    }

    bool transfer(int account1, int account2, long money) {
        if (!isValid(account1) || !isValid(account2) || balance[account1 - 1] < money) return false;
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long money) {
        if (!isValid(account)) return false;
        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long money) {
        if (!isValid(account) || balance[account - 1] < money) return false;
        balance[account - 1] -= money;
        return true;
    }

private:
    bool isValid(int account) {
        return account >= 1 && account <= n;
    }
};


    
    /**
     * Your Bank object will be instantiated and called as such:
     * Bank* obj = new Bank(balance);
     * bool param_1 = obj->transfer(account1,account2,money);
     * bool param_2 = obj->deposit(account,money);
     * bool param_3 = obj->withdraw(account,money);
     */