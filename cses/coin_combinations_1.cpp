#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
const int m = 1e9 + 7;
int p = 31;

ll dp[1000001];

int main()
{
    int n, x;
    cin >> n >> x;
    vi coins(n);
    fo(i, n)
    {
        cin >> coins[i];
    }
    dp[0] = 1;
    fo(i, x + 1)
    {
        fo(j, n)
        {
            if (i >= coins[j])
            {
                dp[i] += dp[i - coins[j]];
                dp[i] %= m;
            }
        }
    }
    cout << dp[x] % m;
    br;
    return 0;
}