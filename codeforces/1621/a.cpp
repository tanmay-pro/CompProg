#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define endl "\n"
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll ans = -1;
        if (n % 2 == 0)
        {
            if (k <= n / 2)
            {
                ans = 0;
            }
        }
        else
        {
            if (k <= n / 2 + 1)
            {
                ans = 0;
            }
        }
        if (ans == -1)
        {
            cout << ans;
            br;
        }
        else
        {
            fo(i, n)
            {
                fo(j, n)
                {
                    if (i == j && i % 2 == 0 && k != 0)
                    {
                        cout << 'R';
                        k--;
                    }
                    else
                    {
                        cout << '.';
                    }
                }
                br;
            }
        }
    }
    return 0;
}