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
ll sizeSet[VAL];
ll experience[VAL] = {0};
ll extra[VAL] = {0};

void createSet(ll v)
{
    parent[v] = v;
    sizeSet[v] = 1; // Based on size of Tree
}

ll findSet(ll v)
{
    if (parent[v] == v)
        return v;
    return findSet(parent[v]);
}

void unionSets(ll a, ll b)
{
    a = findSet(a);
    b = findSet(b);
    if (a != b)
    {
        if (sizeSet[a] < sizeSet[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sizeSet[a] += sizeSet[b];
        extra[b] = experience[a];
    }
}

ll experienceFunc(ll x)
{
    if (parent[x] == x)
        return experience[x];
    return experienceFunc(parent[x]) + experience[x] - extra[x];
}

int main()
{
    amazing;
    ll n, m, x, y;
    cin >> n >> m;
    Fo(i, 1, n + 1)
    {
        createSet(i);
    }
    while (m--)
    {
        string str;
        cin >> str;
        if (str == "join")
        {
            cin >> x >> y;
            unionSets(x, y);
        }
        else if (str == "get")
        {
            cin >> x;
            cout << experienceFunc(x);
            br;
        }
        else
        {
            cin >> x >> y;
            ll par = findSet(x);
            experience[par] += y;
        }
    }
    return 0;
}