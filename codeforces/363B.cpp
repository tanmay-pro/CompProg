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
    ll n, k;
    cin >> n >> k;
    ll sum[n];
    vl h;
    fo(i, n)
    {
        ll x;
        cin >> x;
        h.push_back(x);
        sum[i] = 0;
    }
    fo(i, k)
    {
        sum[0] += h[i];
    }
    Fo(i, 1, n - k + 1)
    {
        sum[i] = sum[i - 1] - h[i - 1] + h[i + k - 1];
    }
    ll index = 0;
    ll el = m;
    fo(i, n - k + 1)
    {
        if (sum[i] < el)
        {
            index = i;
            el = sum[i];
        }
    }
    cout << index + 1;
    br;
    return 0;
}