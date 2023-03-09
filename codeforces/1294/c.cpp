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

void primeFactors(ll n, map<ll, ll> &m)
{
    while (n % 2 == 0)
    {
        m[2]++;
        n = n / 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            m[i]++;
            n = n / i;
        }
    }
    if (n > 2)
        m[n]++;
}

int main()
{
    amazing;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        map<ll, ll> ans;
        primeFactors(n, ans);
        ll sum = 0, numFactors = 0;
        tr(ans, it)
        {
            sum += it->second;
            numFactors++;
        }
        ll checkVal = 0;
        if (numFactors == 1)
        {
            checkVal = 6;
        }
        else if (numFactors == 2)
        {
            checkVal = 4;
        }
        else
        {
            checkVal = 3;
        }
        if (sum >= checkVal)
        {
            cout << "YES" << endl;
            if (checkVal == 6)
            {
                ll x = 1;
                tr(ans, it)
                {
                    x = it->first;
                }
                cout << x << " " << x * x << " " << n / (x * x * x) << endl;
            }
            else
            {
                ll x = 1, y = 1;
                tr(ans, it)
                {
                    if (x != 1 && y == 1)
                        y = it->first;
                    else if (x == 1)
                        x = it->first;
                }
                cout << x << " " << y << " " << n / (x * y) << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}