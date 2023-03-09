#include <bits/stdc++.h>
using namespace std;
// code for implementing binary search
/*lli l = -1, r = size;while (r > l + 1){ lli mid = l + (r - l) / 2; if (array[mid] <= val)l = mid;elser = mid;}*/
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vvl adj(n + 1);
        fo(i, n - 1)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        if(adj[k].size() <= 1)
        {
            cout << "Ayush" << endl;
            continue;
        }
        ll sum = 0;
        fo(i, adj[k].size())
        {
            ll count = 1;
            ll start = adj[k][i];
            queue<ll> q;
            q.push(start);
            vl visited(n + 1, 0);
            visited[start] = 1;
            visited[k] = 1;
            while (!q.empty())
            {
                ll curr = q.front();
                q.pop();
                for (auto x : adj[curr])
                {
                    if (!visited[x])
                    {
                        visited[x] = 1;
                        q.push(x);
                        count++;
                    }
                }
            }
            sum += count;
        }
        if(sum % 2 == 0)
            cout << "Ashish" << endl;
        else
            cout << "Ayush" << endl;
    }
    return 0;
}