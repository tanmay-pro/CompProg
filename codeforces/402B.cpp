#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
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
    ll n, k;
    cin >> n >> k;
    vl a(n);
    fo(i, n)
    {
        cin >> a[i];
    }
    ll min_ans = MOD;
    ll min_first_height = MOD;
    Fo(i, 1, 1001)
    {
        ll ans = 0;
        ll sum = i;
        fo(j, n)
        {
            if (a[j] != sum)
            {
                ans++;
            }
            sum += k;
        }
        if (ans < min_ans)
        {
            min_ans = ans;
            min_first_height = i;
        }
    }
    cout << min_ans;
    br;
    fo(i, n)
    {
        if (min_first_height > a[i])
        {
            cout << "+" << i + 1 << " " << min_first_height - a[i];
            br;
        }
        else if (min_first_height < a[i])
        {
            cout << "-" << i + 1 << " " << a[i] - min_first_height;
            br;
        }
        min_first_height += k;
    }
    return 0;
}