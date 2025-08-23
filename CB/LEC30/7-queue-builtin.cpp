#include <iostream>
#include <queue>
using namespace std;

int main()
{
    char ch;

    int freq[26] = {0};

    queue<char> q;
    while (true)
    {
        cin >> ch;
        freq[ch - 'a']++;

        if (freq[ch - 'a'] == 1)
        {
            q.push(ch);
        }

        while (!q.empty() && freq[q.front() - 'a'] > 1)
        {
            q.pop();
        }

        if (q.empty())
        {
            cout << -1 << " ";
        }
        else
        {
            cout << q.front() << " ";
        }
    }
}