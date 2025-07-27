#include <iostream>
using namespace std;

void printPath(char path[][10], int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    
}

void f(char maze[][10], char path[][10], int m, int n, int i, int j)
{

    if(i == m || j == n) 
    {
        return;
    }

    if (maze[i][j] == 'X')
    {
        return;
    }
    // base case

    if (i == m - 1 && j == n - 1)
    {
        path[i][j] = '1';
        printPath(path,m,n);
        path[i][j] = '0';

        return;
    }

    // recursive case

    // f(i , j)  = check if there a path from (i,j) to (m-1,n-1) 

    // option 1 : moves right

    // option 2 : moves down

    path[i][j] = '1';

    f(maze, path,m,n,i,j+1);

    f(maze,path,m,n,i+1,j);

    path[i][j] = '0'; //backtrack

    return ;
}

int main()
{
    char maze[][10] = {
        "0000",
        "00X0",
        "00XX",
        "0000",
    };

    char path[][10] = {
        "0000",
        "0000",
        "0000",
        "0000",
    };

    int m = 4;
    int n = 4;

    f(maze, path, m, n, 0, 0);
}