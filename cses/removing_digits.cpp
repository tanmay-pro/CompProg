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
ll MOD = 1e9 + 7;
int p = 31;

int main()
{
    amazing;
    ll n;
    cin >> n;
    vl dp(n + 1, MOD);
    dp[0] = 0;
    ll temp = n;
    Fo(i, 1, n + 1)
    {
        vl digits;
        ll temp = i;
        while (temp)
        {
            digits.pb(temp % 10);
            temp /= 10;
        }
        fo(j, digits.size())
        {
            if (i >= digits[j] && dp[i - digits[j]] != MOD)
            {
                dp[i] = min(dp[i], dp[i - digits[j]] + 1);
            }
        }
    }
    cout << dp[n] << endl;
    br;
    return 0;
}