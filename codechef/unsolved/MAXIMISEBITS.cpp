#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
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

ll highestPowerof2(ll n)
{
    // Invalid input
    if (n < 1)
        return 0;

    int res = 1;

    // Try all powers starting from 2^1
    for (ll i = 0; i < 8 * sizeof(ll); i++)
    {
        ll curr = 1 << i;

        // If current power is more than n, break
        if (curr > n)
            break;

        res = curr;
    }

    return res;
}

ll countSetBits(ll n)
{
    ll count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main()
{
    amazing;

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vl powers;
        ll a = 2;
        while (a <= k + 1)
        {
            powers.pb(a - 1);
            a = a * 2;
        }
    }
    return 0;
}