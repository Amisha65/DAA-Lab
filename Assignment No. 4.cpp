#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

void solve(int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftf, vector<int>& upperD, vector<int>& lowerD, int n) 
{
    if (col == n) 
    {
        ans.push_back(board); 
        return;
    }

    for (int row = 0; row < n; row++) 
    {
        if (leftf[row] == 0 && lowerD[row + col] == 0 && upperD[n - 1 + col - row] == 0) 
        {
            board[row][col] = 'Q';

            leftf[row] = 1;
            lowerD[row + col] = 1;
            upperD[n - 1 + col - row] = 1;

            solve(col + 1, board, ans, leftf, upperD, lowerD, n);

            board[row][col] = '.';
            leftf[row] = 0;
            lowerD[row + col] = 0;
            upperD[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n) 
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.')); 

    vector<int> leftf(n, 0), upperD(2 * n - 1, 0), lowerD(2 * n - 1, 0);

    solve(0, board, ans, leftf, upperD, lowerD, n);

    return ans;     
}

void printSolutions(const vector<vector<string>>& solutions) 
{
    for (const auto& board : solutions) 
    {
        for (const auto& row : board) 
        {
            for (const auto& cell : row) 
            {
                cout << cell << " ";
            }
            cout << endl;
        }
        cout << "-------------" << endl;
    }
}

int main() 
{
    int n = 4; 
    vector<vector<string>> solutions = solveNQueens(n);
    
    printSolutions(solutions);
}



// OUTPUT-
// . . Q . 
// Q . . . 
// . . . Q 
// . Q . . 
// -------------
// . Q . . 
// . . . Q 
// Q . . . 
// . . Q . 
// -------------
