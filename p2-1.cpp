#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    string line;
    long long total{0}, lno{0};
    // 12 red, 13 green, 14 blue
    while(getline(cin, line))
    {
        ++lno;
        istringstream is{line};
        line.find(':');
        is.ignore(line.find(':')+1);
        string subline;
        bool game_valid{true};
        while(getline(is, subline, ';') && game_valid)
        {
            istringstream isub{subline};
            int cnt; string color;
            while((isub >> cnt >> color) && game_valid)
            {
                switch(color[0])
                {
                    case 'r':
                    if(cnt > 12) game_valid = false;
                    break;
                    case 'g':
                    if(cnt > 13) game_valid = false;
                    break;
                    case 'b':
                    if(cnt > 14) game_valid = false;
                    break;
                    default:
                    throw "wtf";
                }
            }
        }
        if(game_valid) total += lno;
    }
    cout << total << endl;
    return 0;
}