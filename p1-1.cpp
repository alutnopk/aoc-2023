#include <iostream>
using namespace std;

int main()
{
    auto is_digit_pred = [](char& ch){ return bool(isdigit(ch)); };
    string line;
    long long total_sum{0};
    while(getline(cin, line))
    {
        auto it_first = find_if(line.begin(), line.end(), is_digit_pred);
        auto it_last = find_if(line.rbegin(), line.rend(), is_digit_pred);
        int num_line = int(*it_first - '0')*10 + int(*it_last - '0');
        total_sum += num_line;
    }
    cout << total_sum << endl;
    return 0;
}

// int main()
// {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     string s;
//     long long su{0};
//     while(getline(cin, s))
//     {
//         int dig1{-1}, dig2{-1};
//         for(auto it = s.begin(); it != s.end(); it++)
//         {
//             if(isdigit(*it))
//             {
//                 dig2 = int((*it) - '0');
//                 if(dig1 == -1) dig1 = dig2;
//             }
//         }
//         su += 10*dig1 + dig2;
//     }
//     cout << su << endl;
//     return 0;
// }