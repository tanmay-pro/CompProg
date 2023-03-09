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

void dfs(int x, bool visited[], int color[], int n, vvi& adj)
{
    visited[x] = true;
    for (auto &i : adj[x])
    {
        if (!visited[i])
        {
            if (color[x] == 1)
            {
                color[i] = 0;
            }
            else if (color[x] == 0)
            {
                color[i] = 1;
            }
            dfs(i, visited, color, n ,adj);
        }
    }
}

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vvi adj(n+1);
        for (int i = 1; i <= m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        bool visited[n + 1];
        memset(visited, false, sizeof(visited));
        int color[n + 1];
        memset(color, -1, sizeof(color));
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                color[i] = 0;
                dfs(i, visited, color, n, adj);
            }
        }
        ll c = 0;
        Fo(i, 1, n + 1)
        {
            if (color[i] == 0)
            {
                c++;
            }
        }
        int x = min(c, n-c);
        cout << x;
        br;
        if(x == n-c)
        {
            Fo(i, 1, n + 1)
            {
                if (color[i] == 1)
                {
                    cout << i << " ";
                }
            }
        }
        else 
        {
            Fo(i, 1, n + 1)
            {
                if (color[i] == 0)
                {
                    cout << i << " ";
                }
            }
        }   
        br;
    }
    return 0;
}