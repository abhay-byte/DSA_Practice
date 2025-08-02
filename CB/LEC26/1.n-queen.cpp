#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:

    bool isValid(int r, int n, vector<string> board,int j)
    {
        // check if we can place the Qr in the jth column of row r;

        // 1. check in the jth column if there if any previously placed queen Qi where 0<=i<=r-1

        for(int i = r - 1; i >= 0 ; i--)
        {
            if(board[i][j] == 'Q')
            {
                //there is prev placed queen in the jth column of the board therefore u cannot place Qr in the jth column of row
                return false;
            }
        }

        // 2. check in the right diagonal of the jth column if there is any previously placed queen Qi where 0<=i<=r-1

        for(int i = r - 1, step = 1; i >= 0 && step+j < n ; i--,step++)
        {
            if(board[i][j+step] == 'Q')
            {
                //there is prev placed queen along the right diagonal in the jth column of the board therefore u cannot place Qr in the jth column of row
                return false;
            }
        }        

        // 3. check in the left diagonal of the jth column if there is any previously placed queen Qi where 0<=i<=r-1

        for(int i = r - 1, step = 1; i >= 0 && step-j >= 0 ; i--,step++)
        {
            if(board[i][j-step] == 'Q')
            {
                //there is prev placed queen along the left diagonal in the jth column of the board therefore u cannot place Qr in the jth column of row
                return false;
            }
        }   

        return true;

    }

    void f(int r, int n, vector<string>& board, vector<vector<string>>& allBoard)
    {
        //base case

        if(r==n)
        { // if you build a valid configuration
            allBoard.push_back(board);
            return;
        }

        //recursive case

        // f(r) = takes decision for Qr to Qn-1

        // decide for Qr

        for(int j = 0; j < n; j++)
        {
            if(isValid(r,n,board,j))
            {
                board[r][j] = 'Q';
                f(r+1,n,board,allBoard);
                board[r][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> allBoards;

        vector<string> board;

        for(int i = 1; i <= n; i++)
        {
            string row(n,'.');
            board.push_back(row);
        }

        f(0,n,board,allBoards);

        return allBoards;
        
    }
};


int main()
{
    Solution obj;

    int n = 4;

    for(vector<string> a: obj.solveNQueens(n))
    {
        for(string b: a)
        {
            cout << b;
            cout << endl;
        }

        cout << endl;
    }
}