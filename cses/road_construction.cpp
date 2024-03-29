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

ll findSet(ll a, vector<ll> &parent)
{
    if (a == parent[a])
        return a;
    return parent[a] = findSet(parent[a], parent);
}

void unionSet(ll a, ll b, vector<ll> &parent, vector<ll> &sz, ll &numcomp, ll &maxSize)
{
    a = findSet(a, parent);
    b = findSet(b, parent);
    if (a != b)
    {
        numcomp--;
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        maxSize = max(maxSize, sz[a]);
    }
}

int main()
{
    amazing;

    ll n, m;
    cin >> n >> m;

    vector<ll> parent(n + 1);
    vector<ll> sz(n + 1, 1);
    fo(i, n + 1)
        parent[i] = i;

    ll numpComp = n;
    ll maxSize = INT_MIN;

    fo(i, m)
    {
        ll a, b;
        cin >> a >> b;
        if (findSet(a, parent) != findSet(b, parent))
        {
            unionSet(a, b, parent, sz, numpComp, maxSize);
        }
        cout << numpComp << " " << maxSize;
        br;
    }

    return 0;
}