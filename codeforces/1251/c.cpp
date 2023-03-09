#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        vector<int> e;
        vector<int> o;
        string str;
        cin >> str;
        char ch;
        for (int i = 0; i < str.length(); i++)
        {
            ch = str[i];
            int x = ch;
            x -= 48;
            if (x % 2 == 0)
            {
                e.push_back(x);
            }
            else
            {
                o.push_back(x);
            }
        }
        e.push_back(11);
        o.push_back(11);
        auto eit = e.begin();
        auto oit = o.begin();
        while ((oit != (o.end() - 1)) || (eit != (e.end() - 1)))
        {
            if (*eit < *oit)
            {
                cout << *eit;
                eit++;
            }
            else
            {
                cout << *oit;
                oit++;
            }
        }
        cout << endl;
    }
}