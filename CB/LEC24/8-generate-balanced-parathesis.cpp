#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<string> result;

void f(int n, char out[], int i, int oc, int cc)
{
    // base case

    if (i == 2*n || (oc == n && cc == n))
    {
        out[i] = '\0';
        result.push_back(string(out));
        return;
    }

    // recurive call
    // option 1 opening bracket
    
    if (oc < n)
    {
        out[i] = '(';
        f(n, out, i + 1, oc + 1, cc);
    }

    // option 2 closing bracket
    if (cc < oc)
    {
        out[i] = ')';
        f(n, out, i + 1, oc, cc + 1);
    }
}

int main()
{
    int n = 5;

    char out[17];

    f(n, out, 0, 0, 0);
}