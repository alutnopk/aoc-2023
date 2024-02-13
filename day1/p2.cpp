#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    long long total{0};
    int dig1{0}, dig2{0};
    vector<string> digits{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    while(getline(cin, s))
    {
        dig1 = dig2 = 0;
        // find first digit
        size_t min_first_idx = s.find_first_of("123456789");
        if(min_first_idx != s.npos)
            dig1 = int(s[min_first_idx]-'0');
        for(int i=0; i<digits.size(); i++)
        {
            string& w = digits[i];
            size_t idx_w = s.find(w);
            if(idx_w != s.npos && (min_first_idx == s.npos || idx_w < min_first_idx))
            {
                min_first_idx = idx_w;
                dig1 = i+1;
            }
        }
        // find last digit
        size_t max_last_idx = s.find_last_of("123456789");
        if(max_last_idx != s.npos)
            dig2 = int(s[max_last_idx]-'0');
        for(int i=0; i<digits.size(); i++)
        {
            string& w = digits[i];
            size_t idx_w = s.rfind(w);
            if(idx_w != s.npos && (max_last_idx == s.npos || idx_w+w.size()-1 > max_last_idx))
            {
                max_last_idx = idx_w;
                dig2 = i+1;
            }
        }
        total += 10*dig1 + dig2;
    }
    cout << total << endl;
    return 0;
}

// class FSM
// {
//     // FSM[prevstate][transition] = newstate
//     vector<vector<int>> T;

//     public:
//     FSM(): T(34, vector<int>(26, 0)) {}

//     void populate()
//     {
//         // state 0
//         T[0]['o'-'a'] = 10;
//         T[0]['t'-'a'] = 12;
//         T[0]['f'-'a'] = 17;
//         T[0]['s'-'a'] = 10;
//         T[0]['e'-'a'] = 10;
//         T[0]['n'-'a'] = 10;
//     }
// };

// int main()
// {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     string s;
//     int dig1{0}, dig2{0};
//     long long total{0};

//     FSM fsm;
//     // populate FSM table

//     while(getline(cin, s))
//     {
//         for(auto it = s.begin(); it != s.end(); it++)
//         {
//             // if digit, done
//             if(isdigit(*it))
//             {
//                 dig1 = int(*it - '0');
//                 break;
//             }
//             // else, perform transition and check if it reaches a terminal state
//         }
//         for(auto it = s.rbegin(); it != s.rend(); it++)
//         {
//             // if digit, done
//             if(isdigit(*it))
//             {
//                 dig2 = int(*it - '0');
//                 break;
//             }
//             // else, perform transition and check if it reaches a terminal state
//         }
//     }
//     return 0;
// }

// int main()
// {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     string s, s2;
//     long long su{0};
//     vector<string> digits{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
//     while(getline(cin, s))
//     {
//         // convert text to digits
//         s2.clear();
//         for(int i=0; i<s.size(); i++)
//         {
//             bool found{false};
//             for(int j=0; j<9 && !found; j++)
//             {
//                 string& w = digits[j];
//                 if(s.substr(i, w.size()) == w)
//                 {
//                     found = true;
//                     s2.append(to_string(j+1));
//                     i += w.size()-1;
//                 }
//             }
//             if(!found) s2.push_back(s[i]);
//         }
//         cout << s2 << "\n";
//     }
//     cout << endl;
//     return 0;
// }