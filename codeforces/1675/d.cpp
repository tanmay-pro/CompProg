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

ll paths = 0;
vvl ans;
vl temp;
ll val = 0;
void dfs(ll v, vvl &adj, ll n, vector<bool> &visited)
{
    visited[v] = true;
    temp.push_back(v);
    for (auto u : adj[v])
    {
        if (!visited[u])
            dfs(u, adj, n, visited);
    }
    if (adj[v].size() == 1)
    {
        paths++;
        ans.push_back(temp);
        temp.clear();
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
        paths = 0;
        val = 0;
        vl a(n);
        vvl adj(n);
        ans.clear();
        ll parver;
        fo(i, n)
        {
            cin >> a[i];
            a[i]--;
            adj[a[i]].pb(i);
            if(i != a[i])
                adj[i].pb(a[i]);
            if (i == a[i])
            {
                parver = i;
            }
        }
        // fo(i, adj.size())
        // {

        //     fo(j, adj[i].size())
        //     {
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        vector<bool> visited(n, false);
        dfs(parver, adj, n, visited);
        cout << paths << endl;
        fo(i, ans.size())
        {
            cout << ans[i].size();
            br;
            tr(ans[i], it)
            {
                cout << *it + 1 << " ";
            }
            br;
        }
        br;
        br;
    }
    return 0;
}