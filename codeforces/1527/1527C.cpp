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
ll MOD = 1e9 + 7;
int p = 31;

ll maxim(ll a, ll b, ll c)
{
    ll max_val = max(a, b);
    return max(max_val, c);
}

ll minim(ll a, ll b, ll c)
{
    ll min_val = min(a, b);
    return min(min_val, c);
}

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        ll count[n + 5];
        ll count2[n + 5];
        fo(i, n + 5)
        {
            count[i] = 0;
            count2[i] = 0;
        }
        ll sum = 0;
        fo(i, n)
        {
            cin >> a[i];
            count[a[i]]++;
            count2[a[i]]++;
        }
        fo(i, n + 5)
        {
            if (count[i] > 1)
                sum += count[i] * (count[i] - 1) / 2;
        }
        ll ans = sum;
        ll *ptr = &a[0];
        ll *end = &a[n - 1];
        fo(i, n - 2)
        {
            ll num = *end;
            ll val = count[num];
            end--;
            if (val > 1)
            {
                ans += sum - val * (val - 1) / 2 + (val - 1) * (val - 2) / 2;
                count[num]--;
            }
            else
            {
                ans += sum;
            }
        }
        fo(i, n - 2)
        {
            ll num = *ptr;
            ll val = count[num];
            ptr++;
            if (val > 1)
            {
                ans += sum - val * (val - 1) / 2 + (val - 1) * (val - 2) / 2;
                count[num]--;
            }
            else
            {
                ans += sum;
            }
        }
    }
    return 0;
}