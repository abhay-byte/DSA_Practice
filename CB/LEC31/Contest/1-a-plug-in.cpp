#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

string removeConsecutivePairs(string input)
{
    stack<char> s;

    for(char c : input)
    {
        if(!s.empty())
        {
            if(s.top() == c)
            {
                s.pop();
                continue;
            }
        }
        s.push(c);
    }

    string output = "";

    while(!s.empty())
    {
        output += s.top();
        s.pop();
    }

    reverse(output.begin(), output.end());

    return output;
}

int main()
{
    string input;

    cin >> input;

    cout << removeConsecutivePairs(input) << endl;
}

/*
Input:

hhoowaaaareyyoouu

Output:

wre

------------------------------------

Input:

reallazy

Output:

rezy

------------------------------------

Input:

abacabaabacabaa

Output:

a

------------------------------------


*/