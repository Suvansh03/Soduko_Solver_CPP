// THIS CODE IS CONTRIBUTED BY SUVANSH GUPTA
#include<iostream>
using namespace std;

bool isSafe(int row , int col , int board[9][9] , int val)
{
    for(int i=0 ; i<9 ; i++)
    {
        if(board[row][i] == val)
            return false;
        
        if(board[i][col] == val)
            return false;
        
        if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == val)
            return false;
    }
    return true;
}
bool solve(int board[9][9])
{
    int n = 9;
    for(int row = 0; row < n; row++ )
    {
        for(int col = 0; col < n; col++)
        {
            if(board[row][col] == 0)
            {
                for(int val = 1; val<=9; val++)
                {
                    if(isSafe(row, col, board, val))
                    {
                        board[row][col] = val;
                        bool SolPossible = solve(board);

                        if (SolPossible)
                            return true;
                        else
                            board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solve_sudoku(int matrix[9][9])
{
    solve(matrix);
    for (int i=0 ; i<9 ; i++)
    {
        for(int j=0 ; j<9 ; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout << endl;
    }
}

int main()
{
    int array[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                        {0, 0, 3, 0, 1, 0, 0, 8, 0},
                        {9, 0, 0, 8, 6, 3, 0, 0, 5},
                        {0, 5, 0, 0, 9, 0, 6, 0, 0},
                        {1, 3, 0, 0, 0, 0, 2, 5, 0},
                        {0, 0, 0, 0, 0, 0, 0, 7, 4},
                        {0, 0, 5, 2, 0, 6, 3, 0, 0}
                        };
    solve_sudoku(array);
    return 0;
}

// THIS CODE IS CONTRIBUTED BY SUVANSH GUPTA
