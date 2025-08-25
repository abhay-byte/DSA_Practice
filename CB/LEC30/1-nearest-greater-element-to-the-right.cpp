#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    vector<int> input = {5, 3, 6, 7, 2, 1, 4};
    int n = 7;

    for(int i : input)
    {
        cout << i << " ";
    }
    cout << endl;

    stack<int> track;

    track.push(input[n - 1]);
    input[n - 1] = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        track.push(input[i]);
        while (true)
        {


            if (track.empty())
            {
                track.push(input[i]);
                input[i] = -1;
                break;
            }
            
            if (input[i] < track.top())
            {
                input[i] = track.top();
                break;
            }
            else
            {
                track.pop();
            }
        }



    }

    for(int i : input)
    {
        cout << i << " ";
    }
    cout << endl;
}