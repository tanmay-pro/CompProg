#include <bits/stdc++.h>
using namespace std;
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
#define VAL (ll)2e5 + 9

ll parent[VAL];
ll sizeArray[VAL];
ll rankArray[VAL];
ll hasC[VAL];

void createSet(ll v, ll x)
{
    parent[v] = v;
    // rankArray[v] = 0; // Based on Depth of Tree
    sizeArray[v] = 1; // Based on size of Tree
    if (x == 0)
        hasC[v] = 0;
    else
        hasC[v] = 1;
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
    //     if(rankArray[a] < rankArray[b])
    //         swap(a, b);
    //     parent[b] = a;
    //     if (rankArray[a] == rankArray[b])
    //         rankArray[a]++;
    // }
    if (a != b)
    {
        if (sizeArray[a] < sizeArray[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sizeArray[a] += sizeArray[b];
        hasC[a] = hasC[a] || hasC[b];
    }
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
        vl permA;
        vl permB;
        fo(i, n)
        {
            ll a;
            cin >> a;
            permA.pb(a - 1);
        }
        fo(i, n)
        {
            ll b;
            cin >> b;
            permB.pb(b - 1);
        }
        vl permC;
        fo(i, n)
        {
            ll c;
            cin >> c;
            permC.pb(c - 1);
        }
        fo(i, n)
        {
            createSet(permA[i], permC[i]);
        }
        fo(i, n)
        {
            unionSets(permA[i], permB[i]);
        }
        vl count(n, 0);
        fo(i, n)
        {
            if (permC[i] != -1 || permA[i] == permB[i])
            {
                count[findSet(permA[i])]++;
            }
        }
        ll ans = 1;
        fo(i, n)
        {
            if (count[i] == 0 && findSet(i) == i)
            {
                ans = (ans *2) % MOD;
            }
        }
        cout << ans << endl;
    }

    return 0;
}