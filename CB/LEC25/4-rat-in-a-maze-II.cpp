#include <iostream>
using namespace std;

int f(char maze[][10], int m, int n, int i, int j)
{

    if(i == m || j == n) 
    {
        return 0;
    }

    if (maze[i][j] == 'X')
    {
        return 0;
    }
    // base case

    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }

    // recursive case

    // f(i , j)  = check if there a path from (i,j) to (m-1,n-1) 

    // option 1 : moves right

    // option 2 : moves down

    int x = f(maze,m,n,i,j+1);

    int y = f(maze,m,n,i+1,j);


    return x+y;
}

int main()
{
    char maze[][10] = {
        "0000",
        "00X0",
        "00XX",
        "0000",
    };

    int m = 4;
    int n = 4;

    cout << f(maze, m, n, 0, 0);
}