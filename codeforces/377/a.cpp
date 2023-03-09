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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> v(n, vector<char>(m));
    ll existingWalls = 0;
    ll someDot = 0;
    fo(i, n)
    {
        fo(j, m)
        {
            cin >> v[i][j];
            if (v[i][j] == '#')
                existingWalls++;
            else
                someDot = m * i + j;
        }
    }
    vector<vector<ll>> adj;
    fo(i, n)
    {
        fo(j, m)
        {
            if (v[i][j] == '#')
            {
                adj.push_back(vl());
                // cout << "i = " << i << " j = " << j << " ";
                // br;
                continue;
            }

            vl temp;
            if (i - 1 >= 0)
            {
                if (v[i - 1][j] == '.')
                    temp.pb(m * (i - 1) + j);
            }
            if (i + 1 < n)
            {
                if (v[i + 1][j] == '.')
                    temp.pb(m * (i + 1) + j);
            }
            if (j - 1 >= 0)
            {
                if (v[i][j - 1] == '.')
                    temp.pb(m * i + j - 1);
            }
            if (j + 1 < m)
            {
                if (v[i][j + 1] == '.')
                    temp.pb(m * i + j + 1);
            }
            adj.push_back(temp);
        }
    }

    ll connectDots = n * m - existingWalls - k;
    bool check = false;

    ll start = someDot;
    vector<bool> visited(n * m, false);
    ll count = 1;
    vl ans;
    ans.pb(start);
    stack<ll> s;
    s.push(start);
    visited[start] = true;
    while (!s.empty())
    {
        if (count == connectDots)
            break;
        ll v = s.top();
        s.pop();
        for (ll u : adj[v])
        {
            if (!visited[u])
            {
                s.push(u);
                count++;
                ans.pb(u);
            }
            visited[u] = true;

            if (count == connectDots)
                break;
        }
    }
    sort(ans.begin(), ans.end());
    vector<vector<char>> ansV(n, vector<char>(m, 'X'));
    fo(i, n)
    {
        fo(j, m)
        {
            if (v[i][j] == '#')
                ansV[i][j] = '#';
            if (binary_search(ans.begin(), ans.end(), m * i + j))
                ansV[i][j] = '.';
        }
    }
    fo(i, n)
    {
        fo(j, m)
        {
            cout << ansV[i][j];
        }
        br;
    }

    return 0;
}