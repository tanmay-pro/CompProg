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

int MOD = 1e9 + 7;

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl a(1, 0), b(1, 0);
        ll x, y;
        vl tm(1, 0);
        fo(i, n)
        {
            cin >> x;
            cin >> y;
            a.push_back(x);
            b.push_back(y);
        }
        fo(i, n)
        {
            ll x;
            cin >> x;
            tm.push_back(x);
        }
        ll sum_time = 0;
        Fo(i, 1, n + 1)
        {
            // cout << sum_time << endl;
            sum_time += a[i] - b[i - 1] + tm[i];
            // cout << sum_time << endl;
            if (sum_time + ceil(((double)(b[i] - a[i])) / 2.0) < b[i])
            {
                sum_time += b[i] - a[i];
                if (i == n)
                {
                    sum_time -= b[i] - a[i];
                }
            }
            else
            {
                sum_time += ceil(((double)(b[i] - a[i])) / 2.0);
                if (i == n)
                {
                    sum_time -= ceil(((double)(b[i] - a[i])) / 2.0);
                }
            }
        }
        cout << sum_time;
        br;
    }
    return 0;
}