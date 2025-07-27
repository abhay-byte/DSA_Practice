#include <iostream>
using namespace std;

bool f(char maze[][10], int m, int n, int i, int j)
{

    if(i == m || j == n) 
    {
        return false;
    }

    if (maze[i][j] == 'X')
    {
        return false;
    }
    // base case

    if (i == m - 1 && j == n - 1)
    {
        return true;
    }

    // recursive case

    // f(i , j)  = check if there a path from (i,j) to (m-1,n-1) 

    if(i == m - 1)
    {
        return f(maze,m,n,i,j+1);
    }

    if(j == n - 1)
    {
        return f(maze,m,n,i+1,j);
    }

    // option 1 : moves right

    // option 2 : moves down

    return  f(maze,m,n,i+1,j) ||  f(maze,m,n,i,j+1);
}

int main()
{
    char maze[][10] = {
        "0000",
        "0XX0",
        "00XX",
        "0000",
    };

    int m = 4;
    int n = 4;

    cout << f(maze, m, n, 0, 0);
}