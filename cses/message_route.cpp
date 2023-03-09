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
typedef queue<int> qi;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
ll MOD = 1e9 + 7;
int p = 31;

int main()
{
    amazing;
    int n, m;
    cin >> n >> m;
    vvi adj(n+1);
    fo(i, m)
    {
        int a, b;
        cin >> a >> b;
        adj[b].pb(a);
        adj[a].pb(b);
    }
    qi q;
    vector<bool> used(n + 1);
    vi d(n + 1), p(n + 1);

    q.push(1);
    used[1] = true;
    p[1] = -1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : adj[v])
        {
            if (!used[u])
            {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
    if (!used[n])
    {
        cout << "IMPOSSIBLE";
        br;
    }
    else
    {
        vi path;
        for (int v = n; v != -1; v = p[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << path.size();
        br;
        for (int v : path)
            cout << v << " ";
    }
    return 0;
}