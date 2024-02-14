#include <bits/stdc++.h>

namespace Parse
{
    int WINCOUNT, NUMCOUNT;
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
    // self-explanatory
    int num_matches(const std::string &line)
    {
        int ptr{0}, num{};
        std::set<int> winset{};

        while (line[ptr] != ':')
            ptr++;
        ptr++;

        for (int i{0}; i < WINCOUNT; i++)
        {
            winset.insert(Parse::get_next_num(line, ptr));
        }

        int num_matches{0};
        for (int i{0}; i < NUMCOUNT; i++)
        {
            if (winset.find(Parse::get_next_num(line, ptr)) != winset.end())
                num_matches++;
        }
        return num_matches;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: ./a.out <winning-number-count-per-line> <possessed-number-count-per-line>" << std::endl;
        return EXIT_FAILURE;
    }

    Parse::WINCOUNT = std::atoi(argv[1]), Parse::NUMCOUNT = std::atoi(argv[2]);
    // 
    std::vector<int> cards_won{}, total_cards{};
    for (std::string line{}; std::getline(std::cin, line);)
    {
        cards_won.push_back(Parse::num_matches(line));
        total_cards.push_back(1);
    }
    size_t sz = cards_won.size();
    for (size_t i{0}; i < sz; i++)
    {
        // add total_cards[i] to the next cards_won[i] positions of total_cards
        for (size_t j = i + 1; j < sz && j <= i + cards_won[i]; j++)
        {
            total_cards[j] += total_cards[i];
        }
    }
    std::cout << std::accumulate(total_cards.begin(), total_cards.end(), 0) << std::endl;
    return 0;
}