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
#define file_read                      \
    freopen("moocast.in", "r", stdin); \
    freopen("moocast.out", "w", stdout);
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

vpl cows(205);
vl power(205);
vl adj[205];
vector<bool> visited(205);

ll dfs(int x)
{
    visited[x] = true;
    int val = 0;
    for (auto &i : adj[x])
    {
        if (!visited[i])
        {
            val += dfs(i) + 1;
        }
    }
    return val;
}

int main()
{
    file_read;
    amazing;
    ll n;
    cin >> n;
    fo(i, n)
    {
        cin >> cows[i].first >> cows[i].second;
        cin >> power[i];
    }
    fo(i, n)
    {   
        fo(j, n)
        {
            if (hypot(cows[i].first - cows[j].first, cows[i].second - cows[j].second) <= power[i] && (i != j))
            {
                adj[i].pb(j);
            }
        }
    }
    ll ans = 0;
    fo(i, n)
    {
        visited.assign(n, false);
        ans = max(ans, dfs(i));
    }
    cout << ans + 1;
    br;
    return 0;
}