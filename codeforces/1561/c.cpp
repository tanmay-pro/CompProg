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

ll getMaxStart(vl mons)
{
    fo(i, mons.size())
    {
        mons[i] -= i;
    }
    return (*max_element(mons.begin(), mons.end()) + 1);
}

int main()
{
    amazing;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vpl data(n);
        fo(i, n)
        {
            ll k;
            cin >> k;
            vl mons;
            fo(i, k)
            {
                ll x;
                cin >> x;
                mons.pb(x);
            }
            data[i].first = getMaxStart(mons);
            data[i].second = k;
        }
        sort(data.begin(), data.end());
        ll ans = data[0].ff;
        ll valSofar = data[0].ff;
        Fo(i, 1, n)
        {
            ll end = valSofar + data[i - 1].ss;
            if (end < data[i].ff)
            {
                ans += data[i].ff - end;
                valSofar = data[i].ff;
            }
            else
            {
                valSofar = end;
            }
        }
        cout << ans << endl;
    }
    return 0;
}