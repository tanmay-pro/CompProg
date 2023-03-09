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
vvl adj;
ll n;
string colors;
void dfs(ll v, vvl &adj, vl &visited, vl &countWhite, vl &countBlack)
{
    visited[v] = true;
    for (ll u : adj[v])
    {
        if (!visited[u])
            dfs(u, adj, visited, countWhite, countBlack);
        if (colors[u] == 'B')
        {
            countBlack[v] += countBlack[u] + 1;
            countWhite[v] += countWhite[u];
        }
        else
        {
            countWhite[v] += countWhite[u] + 1;
            countBlack[v] += countBlack[u];
        }
    }
}

int main()
{
    amazing;
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vl a(n - 1);
        fo(i, n - 1)
        {
            cin >> a[i];
            a[i]--;
        }
        cin >> colors;
        vvl adj(n);
        vl visted(n, false);
        vl countWhite(n, 0);
        vl countBlack(n, 0);
        fo(i, n - 1)
        {
            adj[a[i]].push_back(i + 1);
            // adj[i + 1].push_back(a[i]);
        }
        dfs(0, adj, visted, countWhite, countBlack);
        ll ans = 0;
        fo(i, n)
        {
            if (colors[i] == 'W' && (countWhite[i] + 1 == countBlack[i]))
                ans++;
            else if (colors[i] == 'B' && (countBlack[i] + 1 == countWhite[i]))
                ans++;
        }
        // fo(i, n)
        // {
        //     cout << countBlack[i] << " " << countWhite[i] << endl;
        // }
        cout << ans << endl;
    }
    return 0;
}