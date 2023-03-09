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

const int val = 2e5 + 5;
vl adj[val];
ll dfsval[val] = {0};

void dfs(int x)
{
    dfsval[x] = 0;
    for (auto &i : adj[x])
    {
        dfs(i);
        dfsval[x] += dfsval[i] + 1;
    }
}

int main()
{
    amazing;
    ll n;
    cin >> n;
    fo(i, n - 1)
    {
        ll x;
        cin >> x;
        adj[x].pb(i + 2);
    }
    dfs(1);
    Fo(i, 1, n + 1)
    {
        cout << dfsval[i] << " ";
    }
    return 0;
}
