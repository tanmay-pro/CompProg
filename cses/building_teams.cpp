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
int p = 31;
const int val = 1e5 + 5;
vl adj[val];
bool visited[val];

void dfs(int x, map<ll, ll> &rel)
{
    visited[x] = true;
    for (auto &i : adj[x])
    {
        
        if (!visited[i])
        {
            if(rel[x] == 1)
            {
                rel[i] = 2;
            }
            else
            {
                rel[i] = 1;
            }
            dfs(i, rel);
        }
    }
}

int main()
{
    amazing;
    ll n, m;
    cin >> n >> m;
    fo(i, m)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    map<ll, ll> rel;
    Fo(i, 1, n+1)
    {
        if(!visited[i])
        {
            rel[i] = 1;
            dfs(i, rel);
        }
    }
    Fo(i, 1, n + 1)
    {
        for(auto &x: adj[i])
        {
            if(rel[i] == rel[x])
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    Fo(i, 1, n+1)
    {
        cout << rel[i] << " ";
    }
    br;
    return 0;
}