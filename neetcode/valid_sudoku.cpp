/*#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      vector<unordered_set<char>> rowSet;
      vector<unordered_set<char>> colSet;
      unordered_set<char> row;
      unordered_set<char> col;

      int i;
      int j;
      
      for (i = 0; i < 9; i++)
      {
        row.clear();
        col.clear();
        
        for (j = 0; j < 9; j++)
        {
          char rowWise = board[i][j];
           char colWise = board[j][i];

        auto result1 = row.insert(rowWise);
        bool condition1 = result1.second;
          if(condition1)
            continue;
          else {
            return false;
          }

        auto result2 = col.insert(colWise);
        bool condition2 = result2.second;
        if(condition2)
          continue;
        else {
          return false;
          }  
        }
      }

      return true;
    }
};*/
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rowSet(9);
        vector<unordered_set<char>> colSet(9);
        vector<unordered_set<char>> boxSet(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num == '.') continue;

                // Check row
                if (rowSet[i].count(num)) return false;
                rowSet[i].insert(num);

                // Check column
                if (colSet[j].count(num)) return false;
                colSet[j].insert(num);

                // Check 3x3 box
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (boxSet[boxIndex].count(num)) return false;
                boxSet[boxIndex].insert(num);
            }
        }

        return true;
    }
};
