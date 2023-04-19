#include <bits/stdc++.h>
using namespace std;
bool isSafe(int i, int j, int n, vector<vector<int>> &grid)
{
    for (int k = 0; k < grid.size(); k++)
    {
        if (grid[k][j] == n || grid[i][k] == n)
            return false;
    }
    int s = sqrt(grid.size());
    int rs = i - i % s;
    int cs = j - j % s;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (grid[i + rs][j + cs] == n)
                return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>> &grid)
{

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.size(); j++)
        {

            if (grid[i][j] == 0)
            {

                for (int n = 1; n <= grid.size(); n++)
                {
                    if (isSafe(i, j, n, grid))
                    {

                        grid[i][j] = n;

                        if (solve(grid))
                            return true;
                        else
                        {
                            grid[i][j] = 0;
                        }
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> grid(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int a;
            cin >> a;
            grid[i][j] = a;
        }
    }
    solve(grid);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
