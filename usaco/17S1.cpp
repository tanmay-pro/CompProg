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
    freopen("pairup.in", "r", stdin); \
    freopen("pairup.out", "w", stdout);
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
    file_read;
    ll n;
    cin >> n;
    vpl cows;
    fo(i, n)
    {
        ll x, y;
        cin >> x >> y;
        cows.push_back({y, x});
    }
    sort(cows.begin(), cows.end());
    ll sp = 0, ep = n - 1;
    ll ans = LONG_LONG_MIN;

    while (sp <= ep)
    {
        ll c1 = cows[sp].second;
        ll c2 = cows[ep].second;
        ll f1 = cows[sp].first;
        ll f2 = cows[ep].first;

        ans = max(ans, f1 + f2);

        if (c1 > c2)
        {
            cows[sp].second -= c2;
            ep--;
        }
        else if (c2 > c1)
        {
            cows[ep].second -= c1;
            sp++;
        }
        else
        {
            ep--;
            sp++;
        }
    }
    cout << ans;
    return 0;
}