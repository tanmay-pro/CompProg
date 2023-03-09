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
        vvl a(n, vl(n, 0));
        vector<string> str(n);
        fo(i, n)
        {
            cin >> str[i];
        }
        fo(i, n)
        {
            fo(j, n)
            {
                a[i][j] = str[i][j] - '0';
            }
        }
        ll ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        fo(i, n)
        {
            fo(j, n)
            {
                if (visited[i][j] == true)
                    continue;
                visited[i][j] = true;
                visited[j][n - 1 - i] = true;
                visited[n - 1 - i][n - 1 - j] = true;
                visited[n - 1 - j][i] = true;
                map<ll, ll> freq;
                if (a[i][j] == a[j][n - 1 - i] && a[j][n - 1 - i] == a[n - 1 - i][n - 1 - j] && a[n - 1 - i][n - 1 - j] == a[n - 1 - j][i])
                {
                    ;
                }
                else
                {
                    // cout << a[i][j];
                    // cout << a[j][n - 1 - i];
                    // cout << a[n - 1 - i][n - 1 - j];
                    // cout << a[n - 1 - j][i];
                    // br;
                    freq[a[i][j]]++;
                    freq[a[j][n - 1 - i]]++;
                    freq[a[n - 1 - i][n - 1 - j]]++;
                    freq[a[n - 1 - j][i]]++;
                    ans += min(freq[0], freq[1]);
                }
            }
        }
        cout << ans;
        br;
    }
    return 0;
}