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
        vl a(n);
        fo(i, n) cin >> a[i];
        ll minX = 0;
        ll maxX = -1;
        if (is_sorted(a.begin(), a.end()))
        {
            cout << 0 << endl;
            continue;
        }
        fo(i, n - 1)
        {
            if (a[i] > a[i + 1])
            {
                ll midim = a[i] + a[i + 1];
                if (midim % 2 == 0)
                {
                    midim /= 2;
                }
                else
                {
                    midim /= 2;
                    midim++;
                }
                minX = max(minX, midim);
                maxX = max(maxX, a[i]);
            }
        }
        bool flag = false;
        // Fo(i, minX, maxX + 1)
        // {
        //     vl b = a;
        //     fo(j, n)
        //     {
        //         b[j] = abs(b[j] - i);
        //     }
        //     if(is_sorted(b.begin(), b.end()))
        //     {
        //         cout << i << endl;
        //         flag = true;
        //         break;
        //     }
        // }
        ll l = minX;
        ll r = maxX;
        while (r > l + 1)
        {
            ll mid = l + (r - l) / 2;
            vl b = a;
            fo(j, n)
            {
                b[j] = abs(b[j] - mid);
            }
            if (is_sorted(b.begin(), b.end()))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        fo(i, n)
        {
            a[i] = abs(a[i] - l);
        }
        if (is_sorted(a.begin(), a.end()))
        {
            cout << l << endl;
            flag = true;
        }
        if (!flag)
        {
            cout << -1 << endl;
        }
    }
    return 0;
}