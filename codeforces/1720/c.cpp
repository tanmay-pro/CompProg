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
        ll n, m;
        cin >> n >> m;
        vvl a(n, vl(m, 0));
        ll totalOnes = 0;
        fo(i, n)
        {
            string str;
            cin >> str;
            fo(j, m)
            {
                a[i][j] = str[j] - '0';
                if (a[i][j] == 1)
                    totalOnes++;
            }
        }
        ll minOnes = LONG_LONG_MAX;
        ll ans = 0;
        fo(i, n - 1)
        {
            fo(j, m - 1)
            {
                ll count = 0;
                count = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
                if (count < minOnes)
                {
                    minOnes = min(count, minOnes);
                }
            }
        }
        ans = minOnes;
        if (minOnes > 2)
            ans = 2;
        ans += totalOnes - minOnes;
        cout << ans << endl;
    }
    return 0;
}