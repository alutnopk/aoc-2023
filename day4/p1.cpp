#include <bits/stdc++.h>

namespace Parse
{
    // sets num to next number and i to the index after it, else sets num to 0.
    int get_next_num(const std::string &line, int &i)
    {
        int n = line.size();
        while (i < n && !std::isdigit(line[i]))
            i++;

        int num = 0;
        for (; i < n && std::isdigit(line[i]); i++)
        {
            num = 10 * num + int(line[i] - '0');
        }
        return num;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: ./a.out <winning-number-count-per-line> <possessed-number-count-per-line>" << std::endl;
        return EXIT_FAILURE;
    }
    // slight cheating but the program reads how many numbers are in every line, before and after '|'
    int WINCOUNT = std::atoi(argv[1]), NUMCOUNT = std::atoi(argv[2]);

    long long int total_points{0};
    for (std::string line{}; std::getline(std::cin, line);)
    {
        int ptr{0}, num{};
        std::set<int> winset{};
        winset.clear();
        // set cursor after :
        while (line[ptr] != ':')
            ptr++;
        ptr++;
        // insert everything before |
        for (int i{0}; i < WINCOUNT; i++)
        {
            winset.insert(Parse::get_next_num(line, ptr));
        }
        // count how many match
        int points{0};
        for (int i{0}; i < NUMCOUNT; i++)
        {
            if (winset.find(Parse::get_next_num(line, ptr)) != winset.end())
                points = (!points) ? 1 : (points << 1);
        }
        total_points += points;
    }
    std::cout << total_points << std::endl;
    return 0;
}