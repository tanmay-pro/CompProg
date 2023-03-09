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
#define maxn 200007

vector<vector<pair<ll, pll>>> adjList;
vector<bool> visited;
vector<ll> shortest;
vector<ll> blueNode;
vector<ll> ans;
vector<ll> prefix;

void dfs(ll curr)
{
    visited[curr] = true;
    for (auto it : adjList[curr])
    {
        ll elem = it.ff;
        shortest[elem] = min(shortest[elem], shortest[curr] + it.ss.ss);
        blueNode[elem] = blueNode[curr] + it.ss.ff;
        if (!visited[elem])
        {
            dfs(elem);
        }
    }
}

void dfs2(ll curr)
{
    visited[curr] = true;
    prefix.push_back(shortest[curr]);
    ans[curr] = upper_bound(prefix.begin(), prefix.end(), blueNode[curr]) - prefix.begin();
    for (auto it : adjList[curr])
    {
        ll elem = it.ff;
        if (!visited[elem])
        {
            dfs2(elem);
        }
    }
    prefix.pop_back();
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

        adjList.clear();
        adjList.resize(n + 1);

        Fo(i, 1, n)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            pair<ll, pll> p = {i + 1, {y, z}};
            adjList[x].push_back(p);
        }

        visited.clear();
        visited.resize(n + 1, false);

        shortest.clear();
        shortest.resize(n + 1, LONG_LONG_MAX);

        blueNode.clear();
        blueNode.resize(n + 1, 0);

        shortest[1] = 0;
        blueNode[1] = 0;

        dfs(1);

        ans.clear();
        ans.resize(n + 1);

        prefix.clear();

        visited.clear();
        visited.resize(n + 1, false);

        dfs2(1);

        Fo(i, 2, n + 1)
        {
            cout << ans[i] - 1 << " ";
        }

        br;
    }
    return 0;
}