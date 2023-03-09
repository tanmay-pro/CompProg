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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vl a(n);
        fo(i, n)
        {
            cin >> a[i];
        }
        vl b(k);
        fo(i, k)
        {
            cin >> b[i];
        }
        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end());
        ll singCount = 0;
        fo(i, k)
        {
            if (b[i] == 1)
            {
                singCount++;
            }
        }
        ll sum = 0;
        fo(i, singCount)
        {
            sum += 2 * a[i];
        }
        Fo(i, singCount, k)
        {
            sum += a[i];
            b[i]--;
        }
        ll sp = k - 1;
        // cout << sp << " " << sum << endl;
        Fo(i, singCount, k)
        {
            sp += b[i];
            sum += a[sp];
        }
        cout << sum << endl;
    }
    return 0;
}