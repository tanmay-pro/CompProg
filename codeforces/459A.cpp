#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
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
ll MOD = 1e9 + 7;
int p = 31;

ll maxim(ll a, ll b, ll c)
{
    ll max_val = max(a, b);
    return max(max_val, c);
}

ll minim(ll a, ll b, ll c)
{
    ll min_val = min(a, b);
    return min(min_val, c);
}

bool isPerfectSquare(long double x)
{
    // Find floating point value of
    // square root of x.
    long double sr = sqrt(x);

    // If square root is an integer
    return ((sr - floor(sr)) == 0);
}

int main()
{
    amazing;
    // ll t = 1;
    // cin >> t;
    // while (t--)
    // {
    // }
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll x3, x4, y3, y4;
    if (x1 == x2)
    {
        x3 = x1 + abs(y2 - y1);
        y3 = y1;
        x4 = x2 + abs(y2 - y1);
        y4 = y2;
    }
    else if (y1 == y2)
    {
        x3 = x1;
        y3 = y1 + abs(x2 - x1);
        x4 = x2;
        y4 = y2 + abs(x2 - x1);
    }
    else
    {
        x3 = x1;
        y3 = y2;
        x4 = x2;
        y4 = y1;
        if (abs(x2 - x1) != abs(y2 - y1))
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << x3 << " " << y3 << " " << x4 << " " << y4;
    br;
    return 0;
}