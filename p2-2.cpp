#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    long long total{0}, red{0}, blue{0}, green{0};
    while(getline(cin, line)) // read line
    {
        red = blue = green = 0;
        istringstream is{line};
        is.ignore(1+line.find(':'));

        string subline;
        while(getline(is, subline, ';'))
        {
            istringstream issub{subline};
            long long cnt; string color{0};
            while(issub >> cnt >> color)
            {
                switch(color[0])
                {
                    case 'r':
                    red = max(red, cnt);
                    break;
                    case 'g':
                    green = max(green, cnt);
                    break;
                    case 'b':
                    blue = max(blue, cnt);
                    break;
                    default:
                    throw "wtf";
                }
            }
        }
        total += red*green*blue;
    }
    cout << total << endl;
    return 0;
}