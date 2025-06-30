#include <iostream>
#include <vector>
using namespace std;

void sumArrays(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();
    int i = n - 1, j = m - 1;
    int carry = 0;

    vector<int> result;

    // Add digits from the end
    while (i >= 0 || j >= 0 || carry > 0) {
        int digitA = (i >= 0) ? a[i] : 0;
        int digitB = (j >= 0) ? b[j] : 0;

        int sum = digitA + digitB + carry;
        result.push_back(sum % 10);
        carry = sum / 10;

        i--;
        j--;
    }

    // Result is reversed, print it in correct order
    for (int k = result.size() - 1; k >= 0; --k) {
        cout << result[k];
        if (k != 0) cout << ", ";
    }
    cout << ", END" << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int m;
    cin >> m;

    vector<int> b(m);
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    sumArrays(a, b);

    return 0;
}
