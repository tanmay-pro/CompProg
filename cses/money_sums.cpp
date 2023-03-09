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
    ll n;
    cin >> n;
    vl coins(n);
    ll sum = 0;
    fo(i, n)
    {
        cin >> coins[i];
        sum += coins[i];
    }

    vvl dp(n + 1, vl(100000 + 1, 0));
    dp[0][0] = 1;
    Fo(i, 1, n + 1)
    {
        fo(j, sum + 1)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - coins[i - 1] >= 0)
            {
                dp[i][j] = dp[i - 1][j - coins[i - 1]] || dp[i][j];
            }
        }
    }
    vl b;
    Fo(i, 1, sum + 1)
    {
        if (dp[n][i] == 1)
        {
            b.pb(i);
        }
    }
    cout << b.size() << endl;
    fo(i, b.size())
    {
        cout << b[i] << " ";
    }

    return 0;
}