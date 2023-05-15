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
    ll a, b;
    cin >> a >> b;
    vvl dp(a + 1, vl(b + 1, LONG_LONG_MAX));
    fo(i, a + 1)
    {
        dp[i][1] = i - 1;
    }
    fo(i, b + 1)
    {
        dp[1][i] = i - 1;
    }
    dp[1][1] = 0;
    Fo(i, 2, a + 1)
    {
        Fo(j, 2, b + 1)
        {
            //  need to calculate dp[i][j]
            // cout << dp[1][2] << " ";
            // br;
            Fo(k, 1, i)
            {
                dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
            }
            Fo(k, 1, j)
            {
                dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
            }
            if (i == j)
                dp[i][j] = 0;
        }
    }
    cout << dp[a][b];
    br;
    // Fo(i, 1, a + 1)
    // {
    //     Fo(j, 1, b + 1)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     br;
    // }

    return 0;
}