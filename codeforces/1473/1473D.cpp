#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define fo(i, n) for (int i = 0; i < n; i++)
bool binarySearch(vector<int> &arr, ll l, ll r, int x)
{
    while (l <= r)
    {
        ll m = l + (r - l) / 2;
        if (arr[m] == x)
        {
            return true;
        }
        if (arr[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return false; 
}
void ans(int l, int r, string s)
{
    int x = 0;
    vector<int> v(1, 0);
    string res = s.substr(0, l-1) + s.substr(r, s.length() - r);
    for (int i = 0; i < res.length(); i++)
    {
        char c = res[i];
        if (c == '+')
        {
            x++;
        }
        else
        {
            x--;
        }
        bool yes = binarySearch(v, 1, v.size()-1, x);
        if (yes == false)
        {
            v.push_back(x);
        }
    }
    cout << v.size() << endl;
}

int main()
{

    int t = 1;
    si(t);
    while (t--)
    {
        ll n, m;
        sl(n);
        sl(m);
        string str;
        cin >> str;
        fo(i, m)
        {
            ll l, r;
            sl(l);
            sl(r);
            ans(l, r, str);
        }
    }
    return 0;
}