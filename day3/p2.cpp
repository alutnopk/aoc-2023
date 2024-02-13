#include <bits/stdc++.h>

// locate left and right edges of the number at j, given j is already a digit
void find_edges(const std::string &row, int j, int &l, int &r)
{
    l = r = j;
    for (; l >= 0 && std::isdigit(row[l]); l--)
        ;
    l++;
    for (; r < int(row.size()) && std::isdigit(row[r]); r++)
        ;
    r--;
    return;
}

int main()
{
    // read input
    std::vector<std::string> grid{};
    for (std::string line{}; std::getline(std::cin, line);)
    {
        grid.push_back(std::move(line));
    }

    long long int sum_gear_ratio{0};
    for (int i{0}; i < int(grid.size()); i++)
    {
        for (int j{0}; j < int(grid[i].size()); j++)
        {
            std::vector<int> parts{};               // vector of neighboring parts
            std::array<std::bitset<3>, 3> chosen{}; // true if that neighboring digit is already chosen
            parts.clear();
            chosen = {0, 0, 0};

            if (grid[i][j] != '*')
                continue;

            // scan all neighbors
            for (int i2 : {i - 1, i, i + 1})
            {
                if (i2 < 0 || i2 >= int(grid.size()))
                    continue;
                for (int j2 : {j - 1, j, j + 1})
                {
                    if (j2 < 0 || j2 >= int(grid[i2].size()) || !std::isdigit(grid[i2][j2]) || chosen[i2 - i + 1][j2 - j + 1])
                        continue;
                    // find edges of the number
                    int l{}, r{};
                    find_edges(grid[i2], j2, l, r);
                    parts.push_back(std::stoi(grid[i2].substr(l, r - l + 1)));
                    // mark off chosen positions
                    for (int _ = std::max(l - j + 1, 0); _ <= std::min(r - j + 1, 2); _++)
                    {
                        chosen[i2 - i + 1].set(_);
                    }
                }
            }
            if (parts.size() == 2)
            {
                sum_gear_ratio += (parts[0] * parts[1]);
            }
        }
    }
    std::cout << sum_gear_ratio << std::endl;
    return 0;
}