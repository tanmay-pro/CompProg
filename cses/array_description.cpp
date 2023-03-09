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
    ll a[n];
    fo(i, n)
    {
        cin >> a[i];
    }
    vvl dp(n + 1, vl(m + 1, 0));
    Fo(i, 1, n + 1)
    {
        Fo(j, 1, m + 1)
        {
            if (i == 1)
            {
                if (a[0] == 0 || a[0] == j)
                {
                    dp[i][j] = 1;
                }
                else
                    dp[i][j] = 0;
            }
            else
            {
                if (a[i - 1] == 0 || a[i - 1] == j)
                {
                    if (j + 1 <= m)
                        dp[i][j] = dp[i - 1][j - 1] % MOD + dp[i - 1][j] % MOD + dp[i - 1][j + 1] % MOD;
                    else
                        dp[i][j] = dp[i - 1][j - 1] % MOD + dp[i - 1][j] % MOD;
                }
                else
                    dp[i][j] = 0;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i < m + 1; i++)
    {
        ans = ans + dp[n][i];
        ans %= MOD;
    }
    cout << ans;
    br;
    return 0;
}