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
#define VAL (ll)2e5 + 9
int MOD = 1e9 + 7;

ll parent[VAL];
ll sizeArray[VAL];
ll numClusters = 0;
ll maxClusterSize = 0;

void createSet(ll v)
{
    parent[v] = v;
    // rank[v] = 0; // Based on Depth of Tree
    sizeArray[v] = 1; // Based on size of Tree
    maxClusterSize = 1;
    numClusters ++;
}

ll findSet(ll v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = findSet(parent[v]);
}

void unionSets(ll a, ll b)
{
    a = findSet(a);
    b = findSet(b);
    // if (a != b)
    // {
    //     if(rank[a] < rank[b])
    //         swap(a, b);
    //     parent[b] = a;
    //     if (rank[a] == rank[b])
    //         rank[a]++;
    // }
    if (a != b)
    {
        if (sizeArray[a] < sizeArray[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        numClusters--;
        maxClusterSize = max(maxClusterSize, sizeArray[a] + sizeArray[b]);
        sizeArray[a] += sizeArray[b];
    }
}

int main()
{
    amazing;
    ll n, m;
    cin >> n >> m;
    Fo(i, 1, n + 1)
    {
        createSet(i);
    }
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        unionSets(a, b);
        cout << numClusters << " " << maxClusterSize << endl;
    }

    return 0;
}