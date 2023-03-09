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

int main()
{
    amazing;
    ll n, m;
    cin >> n >> m;
    vector<vpl> adj(n);
    fo(i, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dist(n, LONG_LONG_MAX);
    vector<bool> visited(n, false);

    int root = 0;
    pq.push({0, root});
    dist[root] = 0;

    while (!pq.empty())
    {
        pll curr = pq.top();
        pq.pop();
        ll node = curr.second;
        if (visited[node])
            continue;
        visited[node] = true;
        for (auto u : adj[node])
        {
            ll child = u.first;
            ll weight = u.second;
            if (dist[node] + weight < dist[child])
            {
                dist[child] = dist[node] + weight;
                pq.push({dist[child], child});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    br;

    return 0;
}