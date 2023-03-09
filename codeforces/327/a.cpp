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
    vl a(n);
    fo(i, n)
    {
        cin >> a[i];
    }
    vvl dp(n, vl(n, 0));
    fo(i, n)
    {
        if (a[i] == 1)
            dp[i][i] = -1;
        else
            dp[i][i] = 1;
    }

    fo(i, n)
    {
        Fo(j, i + 1, n)
        {
            if (a[j] == 1)
                dp[i][j] = dp[i][j - 1] - 1;
            else
                dp[i][j] = dp[i][j - 1] + 1;
        }
    }
    ll maxim = -1;
    ll maximi = -1;
    ll maximj = -1;
    fo(i, n)
    {
        Fo(j, i, n)
        {
            if (dp[i][j] > maxim)
            {
                maxim = dp[i][j];
                maximi = i;
                maximj = j;
            }
        }
    }
    if (maxim == -1)
    {
        cout << n - 1;
        br;
        return 0;
    }
    ll freq = 0;
    fo(i, maximi)
    {
        if (a[i] == 1)
            freq++;
    }
    Fo(i, maximi, maximj + 1)
    {
        if (a[i] == 0)
            freq++;
    }
    Fo(i, maximj + 1, n)
    {
        if (a[i] == 1)
            freq++;
    }
    cout << freq;
    br;

    return 0;
}