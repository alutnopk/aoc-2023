#include <bits/stdc++.h>

// finds left and right* edges of the first number starting from s[i]
// if no number, sets l = r = n
// *note: r is 1 + the true right edge
void locate_num(const std::string &s, int i, int &l, int &r)
{
    int n = s.size();
    for (; i < n && !std::isdigit(s[i]); i++)
        ;
    l = i;
    for (; i < n && std::isdigit(s[i]); i++)
        ;
    r = i;
    return;
}

// self-evident
bool is_part_num(const std::vector<std::string> &grid, int i, int l, int r)
{
    int n = grid[i].size();
    // check left and right edge
    if ((l - 1 >= 0 && grid[i][l - 1] != '.') || (r < n && grid[i][r] != '.'))
        return true;
    // check upper row in [l-1, r]
    if (i - 1 >= 0)
    {
        auto first_it = grid[i - 1].begin() + std::max(l - 1, 0);
        auto last_it = grid[i - 1].begin() + std::min(r + 1, n);
        auto it = std::find_if(first_it, last_it, [](char c)
                               { return !std::isdigit(c) && c != '.'; });
        if (it != last_it)
            return true;
    }
    // check lower row in [l-1, r]
    if (i + 1 < int(grid.size()))
    {
        auto first_it = grid[i + 1].begin() + std::max(l - 1, 0);
        auto last_it = grid[i + 1].begin() + std::min(r + 1, n);
        auto it = std::find_if(first_it, last_it, [](char c)
                               { return !std::isdigit(c) && c != '.'; });
        if (it != last_it)
            return true;
    }
    return false;
}

int main()
{
    std::string s{};
    std::vector<std::string> grid{};
    while (std::getline(std::cin, s))
    {
        grid.push_back(std::move(s));
    }

    int part_sum{0};
    for (size_t i = 0; i < grid.size(); i++)
    {
        std::string &row = grid[i];
        int l{0}, r{0};
        while (r < row.size())
        {
            locate_num(row, r, l, r);
            if (l == r)
                break; // empty number
            // check surroundings
            if (is_part_num(grid, i, l, r))
            {
                part_sum += std::stoi(row.substr(l, r - l));
            }
        }
    }
    std::cout << part_sum << std::endl;
    return 0;
}