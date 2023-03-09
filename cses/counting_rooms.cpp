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

const int val = 1e3 + 5;
bool visited[val][val];
int n, m;

void dfs(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return ;
    visited[x][y] = true;

    if (!visited[x - 1][y])
        dfs(x - 1, y);
    if (!visited[x + 1][y])
        dfs(x + 1, y);
    if (!visited[x][y - 1])
        dfs(x, y - 1);
    if (!visited[x][y + 1])
        dfs(x, y + 1);
    return;
}
int main()
{
    amazing;
    cin >> n >> m;
    fo(i, n)
    {
        string s;
        cin >> s;
        fo(j, m)
        {
            if (s[j] == '.')
                visited[i][j] = false;
            else
                visited[i][j] = true;
        }
    }
    int ans = 0;
    fo(i, n)
    {
        fo(j, m)
        {
            if (!visited[i][j])
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
    br;
}
