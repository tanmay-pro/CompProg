#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define f first
#define s second
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
    ll t = 1;
    ll n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "NO",
            br;
        return 0;
    }
    cout << "YES";
    br;
    vl ans(2 * n);
    fo(i, n)
    {
        if (i % 2 == 0)
        {
            ans[i] = 2 * i;
            ans[i + n] = 2 * i + 1;
        }
        else
        {
            ans[i + n] = 2 * i;
            ans[i] = 2 * i + 1;
        }
    }
    fo(i, ans.size())
    {
        cout << ans[i] + 1 << " ";
    }
    br;

    return 0;
}