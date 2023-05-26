#include <bits/stdc++.h>
using namespace std;
// code for implementing binary search
/*lli l = -1, r = size;while (r > l + 1){ lli mid = l + (r - l) / 2; if (array[mid] <= val)l = mid;elser = mid;}*/
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (ll i = 0; i < n; i++)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ff first
#define ss second
#define pb push_back
#define file_read                     \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<ll, ll> mii;
typedef map<ll, ll> mll;


ll MOD = 1e9 + 7;

ll findSet(ll a, vector<ll> &parent)
{
    if (parent[a] == a)
        return a;
    return parent[a] = findSet(parent[a], parent);
}

void unionSet(ll a, ll b, vector<ll> &parent, vector<ll> &rank)
{
    a = findSet(a, parent);
    b = findSet(b, parent);
    if (a != b)
    {
        if(rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if(rank[a] == rank[b])
            rank[a]++;
    }
}


int main()
{
    amazing;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;
    fo(i, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.pb({c, a, b});
    }
    sort(edges.begin(), edges.end());

    vector<ll> parent(n + 1);
    vector<ll> rank(n + 1, 0);
    fo(i, n+1)
        parent[i] = i;
    ll ans = 0;
    fo(i, m)
    {
        ll cost = edges[i][0];
        ll e1 = edges[i][1];
        ll e2 = edges[i][2];
        if(findSet(e1, parent) != findSet(e2, parent))
        {
            ans += cost;
            unionSet(e1, e2, parent, rank);
        }
    }
    // cout << ans;
    for(ll i=1; i <n; i++)
    {
        if(findSet(i, parent) != findSet(i+1, parent))
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << ans;
    return 0;
}