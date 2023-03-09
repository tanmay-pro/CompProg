#include <bits/stdc++.h>
using namespace std;
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
    ll sum = 0, ans = 0;
    fo(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 3 != 0)
    {
        cout << 0;
        br;
        return 0;
    }
    vl prefSum(n);
    prefSum[0] = a[0];
    Fo(i, 1, n)
    {
        prefSum[i] = prefSum[i - 1] + a[i];
    }
    vl cnt(n, 0);
    vl sums(n, 0);
    vl suffSum(n);
    suffSum[n - 1] = a[n - 1];
    Fo(i, n - 2, -1)
    {
        suffSum[i] = suffSum[i + 1] + a[i];
    }
    fo(i, n)
    {
        if (suffSum[i] == sum / 3)
        {
            cnt[i] = 1;
        }
    }
    sums[n - 1] = cnt[n - 1];
    Fo(i, n - 2, -1)
    {
        sums[i] = sums[i + 1] + cnt[i];
    }
    fo(i, n - 2)
    {
        if (prefSum[i] == sum / 3)
        {
            ans += sums[i + 2];
        }
    }
    cout << ans;
    br;
    return 0;
}