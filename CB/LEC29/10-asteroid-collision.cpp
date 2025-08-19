#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// https://cplusplus.com/reference/stack/stack/?kw=stack

// time: o(n)
// space: o(n)
vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> s;

    for (int ast : asteroids)
    {
        if (ast < 0 && !s.empty() && s.top() > 0)
        {
            bool flag = true;
            while (!s.empty() && s.top() > 0)
            {
                if (abs(ast) > s.top())
                {
                    s.pop();
                }
                else if (abs(ast) < s.top())
                {
                    flag = false;
                    break;
                }
                else
                {
                    s.pop();
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                s.push(ast);
            }
        }
        else
        {
            s.push(ast);
        }
    }

    vector<int> out;

    while (!s.empty())
    {
        out.push_back(s.top());
        s.pop();
    }

    reverse(out.begin(), out.end());
    return out;
}

int main()
{
    vector<int> in = {7, 3, 2, -8, 2, 4, 1, -4};

    vector<int> out = asteroidCollision(in);

    for (int s : out)
    {
        cout << s << endl;
    }

    return 0;
}