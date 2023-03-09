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
const int val = 1e5 + 5;
vi adj[val];
bool visited[val];
int color[val] = {-1};
void dfs(int x)
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

            dfs(i);
        }
    }
}

int main()
{
    amazing;
    int n;
    cin >> n;
    fo(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[v].pb(u); 
        adj[u].pb(v);   
    }
    color[1] = 0;
    dfs(1);
    ll c1 = 0, c2 = 0;
    Fo(i, 1, n + 1) 
    {
        if (color[i] == 0)
        {
            c1++;
        }
        else if (color[i] == 1)
        {
            c2++;
        }
    }
    ll temp = (c1*c2) - (n-1);
    if (temp >= 0)
        cout << temp;
    else
        cout << 0;
    br;
    return 0;
}