#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ff first
#define ss second
#define pb push_back
#define file_read                     \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

int MOD = 1e9 + 7;

int main()
{
    amazing;
    ll m, s;
    cin >> m >> s;
    ll maxNum, minNum;
    ll digits = m;
    ll currSum = 0;
    string str = "";
    while (m--)
    {
        ll currDigit = 9;
        currSum += currDigit;
        while (currSum > s)
        {
            currDigit--;
            currSum--;
        }
        str += to_string(currDigit);
    }
    string str2 = "";
    currSum = 0;
    ll temp = digits;
    while (temp--)
    {
        ll currDigit = 1;
        if (temp != (digits - 1))
            currDigit = 0;
        currSum += currDigit;
        while ((s - currSum) > temp * 9)
        {
            currDigit++;
            currSum++;
        }
        str2 += to_string(currDigit);
    }
    if (digits == 1 && s == 0)
    {
        minNum = 0;
        maxNum = 0;
        cout << minNum << " " << maxNum << endl;
    }
    else
    {
        if (s > 9 * digits || s == 0)
        {
            minNum = -1;
            maxNum = -1;
            cout << minNum << " " << maxNum << endl;
        }
        else
        {
            cout << str2 << " " << str << endl;
        }
    }
    return 0;
}