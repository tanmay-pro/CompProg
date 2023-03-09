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
    ll n, m;
    cin >> n >> m;
    vvl adj(n + 1);
    fo(i, m)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<bool> visited(n + 1, false);
    stack<ll> s;
    ll count = 0;
    set<ll> toCheck;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            s.push(i);
            visited[i] = true;
            while (!s.empty())
            {
                ll node = s.top();
                s.pop();
                for (auto child : adj[node])
                {
                    if (!visited[child])
                    {
                        s.push(child);
                        visited[child] = true;
                    }
                    else if (visited[child] && child != node)
                    {
                        toCheck.insert(i);
                    }
                }
            }
        }
    }
    for (auto node : toCheck)
    {
        vector<bool> visited2(n + 1, false);
        stack<ll> s2;
        s2.push(node);
        visited2[node] = true;
        bool cycle = true;
        if (adj[node].size() != 2)
        {
            cycle = false;
        }
        while (!s2.empty())
        {
            ll node2 = s2.top();
            s2.pop();
            for (auto child2 : adj[node2])
            {
                if (!visited2[child2])
                {
                    s2.push(child2);
                    if (adj[child2].size() != 2)
                    {
                        cycle = false;
                        break;
                    }
                    visited2[child2] = true;
                }
            }
            if (!cycle)
                break;
        }
        if (cycle)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}