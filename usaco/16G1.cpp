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
#define file_read                      \
    freopen("moocast.in", "r", stdin); \
    freopen("moocast.out", "w", stdout);
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
    vpl coords;
    fo(i, n)
    {
        ll a, b;
        cin >> a >> b;
        coords.pb({a, b});
    }
    vector<pair<ll, pair<ll, ll>>> edges;
    fo(i, n)
    {
        fo(j, n)
        {
            ll x1 = coords[i].ff, y1 = coords[i].ss, x2 = coords[j].ff, y2 = coords[j].ss;
            ll dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            edges.push_back({dist, {i, j}});
            edges.push_back({dist, {j, i}});
        }
    }
    sort(edges.begin(), edges.end());
    // fo(i, edges.size())
    // {
    //     cout << edges[i].ff << " " << edges[i].ss.ff << " " << edges[i].ss.ss << endl;
    // }

    vector<ll> id(n);
    fo(i, n)
    {
        id[i] = i;
    }
    ll heaviestEdge = LONG_LONG_MIN;
    fo(i, edges.size())
    {
        ll e1 = edges[i].ss.ff, e2 = edges[i].ss.ss;
        if (id[e1] != id[e2])
        {
            heaviestEdge = max(heaviestEdge, edges[i].ff);
            int temp = id[e1];
            int temp2 = id[e2];
            fo(j, n)
            {
                if (id[j] == temp)
                    id[j] = temp2;
            }
        }
    }
    cout << heaviestEdge << endl;
    return 0;
}