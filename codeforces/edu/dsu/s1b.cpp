#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
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
#define VAL (ll)3e5 + 9
int p = 31;

ll parent[VAL];
ll rankSet[VAL];
ll maxinSet[VAL] = {LONG_LONG_MIN};
ll mininSet[VAL] = {LONG_LONG_MAX};
ll sizeArray[VAL];

void createSet(ll v)
{
    parent[v] = v;
    maxinSet[v] = v;
    mininSet[v] = v;
    sizeArray[v] = 1;
    // rankSet[v] = 0; // Based on Depth of Tree
    // size[v] = 1; // Based on size of Tree
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
    //     if(rankSet[a] < rankSet[b])
    //         swap(a, b);
    //     parent[b] = a;
    //     mininSet[a] = min(mininSet[b], mininSet[a]);
    //     maxinSet[a] = max(maxinSet[b], maxinSet[a]);
    //     numElem[a] += numElem[b];
    //     if (rankSet[a] == rankSet[b])
    //         rankSet[a]++;
    // }
    if(a != b)
    {
        if(sizeArray[a] < sizeArray[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        maxinSet[a] = max(maxinSet[a], maxinSet[b]);
        mininSet[a] = min(mininSet[a], mininSet[b]);
        sizeArray[a] += sizeArray[b];
    }
}


int main()
{
    amazing;
    ll n, m, x , y;
    cin >> n >> m;
    Fo(i, 1, n+1)
    {
        createSet(i);
    }
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        if (str[0] == 'u')
        {
            cin >> x >> y;
            unionSets(x, y);
        }
        else
        {
            cin >> x;
            ll parentVal = findSet(x);
            cout << mininSet[parentVal] << " " << maxinSet[parentVal] << " " << sizeArray[parentVal] << endl;
        }
    }
    return 0;
}