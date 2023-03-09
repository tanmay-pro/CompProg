#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
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
int m = 1e9 + 7;
int p = 31;

int main()
{
    amazing;
    int n, x;
    cin >> n >> x;
    vi price(n);
    vi pages(n);
    fo(i, n)
    {
        cin >> price[i];
    }
    fo(i, n)
    {
        cin >> pages[i];
    }
    vvi dp(n + 1, vi(x + 1, 0));
    dp[0][0] = 0;
    Fo(i, 1, n + 1)
    {
        fo(j, x + 1)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= price[i - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + pages[i - 1]);
            }
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}