#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<string> grid;
    vector<vector<int>> numbers, chosen;
    for(string s; getline(cin, s);)
    {
        grid.push_back(s);
    }
    int m, n;
    m = int(grid.size()), n = int(grid[0].size());
    for(size_t i{0}; i<m; i++)
    {
        int num{0};
        for(size_t j{0}; j<n; j++)
        {
            if(isdigit(grid[i][j]))
                num = 10*num + int(grid[i][j] - '0');
            else
            {
                num = 0;
                if(grid[i][j]!='.')
                {
                    find_
                }
            }
        }
    }
    return 0;
}