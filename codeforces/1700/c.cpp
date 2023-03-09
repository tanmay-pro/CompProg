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
        ll min = *min_element(a.begin(), a.end());
        ll ans = 0;
        ans += abs(min);
        fo(i, n)
        {
            a[i] -= min;
        }
        // fo(i, n)
        // {
        //     cout << a[i] << " ";
        // }
        // br;
        ll minInd = -1;
        ll minim = LONG_LONG_MAX;
        ll leftZero = -1;
        fo(i, n)
        {
            if (a[i] == 0)
            {
                leftZero = i;
                break;
            }
            else
            {
                if (a[i] < minim)
                {
                    minim = a[i];
                    minInd = i;
                }
            }
        }
        ll maxim = LONG_LONG_MIN;
        if (leftZero != 0)
        {
            Fo(i, minInd + 1, leftZero)
            {
                a[i] -= minim;
            }
            fo(i, minInd + 1)
            {
                if (a[i] > maxim)
                {
                    maxim = a[i];
                }
            }
            if (maxim != LONG_LONG_MIN)
                ans += maxim;
            fo(i, minInd + 1)
            {
                a[i] = 0;
            }
        }
        // fo(i, n)
        // {
        //     cout << a[i] << " ";
        // }
        // br;
        minInd = -1;
        minim = LONG_LONG_MAX;
        ll rightZero = -1;
        Fo(i, n - 1, -1)
        {
            if (a[i] == 0)
            {
                rightZero = i;
                break;
            }
            else
            {
                if (a[i] < minim)
                {
                    minim = a[i];
                    minInd = i;
                }
            }
        }
        // cout << minInd << " " << rightZero << endl;
        if (rightZero != n - 1)
        {
            Fo(i, minInd - 1, rightZero)
            {
                a[i] -= minim;
            }
            maxim = LONG_LONG_MIN;
            Fo(i, minInd, n)
            {
                if (a[i] > maxim)
                {
                    maxim = a[i];
                }
            }
            if (maxim != LONG_LONG_MIN)
                ans += maxim;
            Fo(i, minInd, n)
            {
                a[i] = 0;
            }
        }
        fo(i, n)
        {
            cout << a[i] << " ";
        }
        br;
        fo(i, n)
        {
            ans += a[i];
            ans += a[i];
            ans += a[i];
        }
        cout << ans;
        br;
    }
    return 0;
}