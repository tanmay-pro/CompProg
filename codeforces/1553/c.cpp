#include <bits/stdc++.h>
using namespace std;
// code for implementing binary search
/*lli l = -1, r = size;while (r > l + 1){ lli mid = l + (r - l) / 2; if (array[mid] <= val)l = mid;elser = mid;}*/
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
    ll t;
    cin >> t;
    while (t--)
    {
        string str;
        vl team1(10, 0);
        vl team2(10, 0);
        ll n = 10;
        cin >> str;
        if (str[0] == '1')
        {
            team1[0] = 1;
            team2[0] = -1;
        }
        else if (str[0] == '?')
        {
            team1[0] = 1;
        }
        Fo(i, 1, 10)
        {
            if (str[i] == '1' && i % 2 == 0)
            {
                team1[i] = team1[i - 1] + 1;
                team2[i] = team2[i - 1] - 1;
            }
            else if (str[i] == '1' && i % 2 == 1)
            {
                team1[i] = team1[i - 1] - 1;
                team2[i] = team2[i - 1] + 1;
            }
            else if (str[i] == '?' && i % 2 == 0)
            {
                team1[i] = team1[i - 1] + 1;
                team2[i] = team2[i - 1];
            }
            else if (str[i] == '?' && i % 2 == 1)
            {
                team2[i] = team2[i - 1] + 1;
                team1[i] = team1[i - 1];
            }
            else
            {
                team1[i] = team1[i - 1];
                team2[i] = team2[i - 1];
            }
        }
        ll val = LONG_LONG_MAX;
        fo(i, n)
        {
            ll kicksLeft = n - i - 1;
            if (kicksLeft % 2 == 0)
                kicksLeft /= 2;
            else
                kicksLeft = (kicksLeft + 1) / 2;
            if (team1[i] > kicksLeft)
            {
                val = min(val, (ll)i + 1);
                break;
            }
        }
        fo(i, n)
        {
            ll kicksLeft = n - i - 1;
            kicksLeft /= 2;
            if (team2[i] > kicksLeft)
            {
                val = min(val, (ll)i + 1);
                break;
            }
        }
        if (val > 10)
            val = 10;

        cout << val << endl;
    }
    return 0;
}