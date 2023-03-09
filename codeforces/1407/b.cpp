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
        vl a(n);
        ll checker[n];
        ll max_el = -1;
        ll mi = -1;
        fo(i, n)
        {
            cin >> a[i];
            if (max_el < a[i])
            {
                max_el = a[i];
                mi = i;
            }
            checker[i] = 0;
        }
        vl answer;
        answer.push_back(max_el);
        checker[mi] = 1;
        ll val = max_el;
        fo(i, n - 1)
        {
            ll x = -1;
            ll index = -1;
            ll temp = 0;
            fo(j, n)
            {
                if (__gcd(val, a[j]) > temp && checker[j] == 0)
                {
                    temp = __gcd(val, a[j]);
                    index = j;
                    x = a[j];
                }
            }
            val = temp;
            answer.push_back(x);
            checker[index] = 1;
        }
        fo(i, answer.size())
        {
            cout << answer[i] << " ";
        }
        br;
    }
    return 0;
}