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

string convert(int n, int r)
{
    string ans = "";
    Fo(i, r - 1, -1)
    {
        if (n & (1 << i))
        {
            ans += '1';
        }
        else
        {
            ans += '0';
        }
    }
    return ans;
}

int main()
{
    amazing;
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> numbers;
    fo(i, m + 1)
    {
        ll x;
        cin >> x;
        numbers.pb(x);
    }
    ll ans = 0;
    string fedora = convert(numbers[m], n);
    fo(i, m)
    {
        string cur = convert(numbers[i], n);
        ll asn = 0;
        fo(i, n)
        {
            if (cur[i] != fedora[i])
            {
                asn += 1;
            }
        }
        if (asn <= k)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}