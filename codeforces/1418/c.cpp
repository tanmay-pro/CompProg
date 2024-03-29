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
        ll n;
        cin >> n;
        vl a(n);
        fo(i, n) cin >> a[i];
        
        // if (a[0] == 1)
        //     ans++;
        // ll currSeq = 0;
        // Fo(i, 1, n)
        // {
        //     if (a[i] == 1)
        //         currSeq++;
        //     else
        //     {
        //         ans += currSeq / 3;
        //         currSeq = 0;
        //     }
        // }
        // ans += currSeq / 3;
        // cout << ans;
        // br;

        vvl dp(2, vl(n + 1, LONG_LONG_MAX));
        dp[1][0] = 0;
        for (int j = 0; j < n; j++)
        {
            dp[0][j + 1] = min(dp[0][j + 1], dp[1][j] + a[j]);
            dp[1][j + 1] = min(dp[1][j + 1], dp[0][j]);

            if (j + 2 <= n)
            {
                dp[0][j + 2] = min(dp[0][j + 2], dp[1][j] + a[j + 1] + a[j]);
                dp[1][j + 2] = min(dp[1][j + 2], dp[0][j]);
            }
        }
        cout << min(dp[0][n], dp[1][n]);
        br;
    }
    return 0;
}