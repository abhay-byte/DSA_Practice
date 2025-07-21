#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void f(char inp[], int i)
{
    // base case
    if(inp[i] == '\0')
    {
        return;
    }

    // recursive case

    // f(i) = a fn that replaces all the pi with 3.14
    // in the inp[i...n-1]

    if (inp[i] == 'p' and inp[i + 1] == 'i')
    {
        // replace pi at the i. i+1th index with 3.14

        // shift all the chars starting fro, index i+2 two steps fwd

        int j = i + 2;
        while (inp[j] != '\0')
        {
            j++;
        }

        while (j >= i + 2)
        {
            inp[j + 2] = inp[j];
            j--;
        }

        // now replace at the i,i+1th index with 3.14

        inp[i] = '3';
        inp[i + 1] = '.';
        inp[i + 2] = '1';
        inp[i + 3] = '4';

        // ask ur friend to replace all the pi with 3.14
        // in inp[i+4...n-1]

        f(inp, i + 4);
    }
    else
    {
        // ask ur friend to replace all the pi with 3.14
        // in inp [i+4...n-1]

        f(inp, i + 1);
    }
}

int main()
{

    char inp[20] = "pip";

    f(inp, 0);

    cout << inp << endl;
}

/*

*/