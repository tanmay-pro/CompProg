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
    // ll t = 1;
    // cin >> t;
    // while (t--)
    // {
    // }
    ll n, m;
    cin >> n >> m;
    vl price;
    fo(i, n)
    {
        ll x;
        cin >> x;
        price.push_back(x);
    }
    vl customer(m);
    fo(i, m)
    {
        cin >> customer[i];
    }
    sort(price.begin(), price.end());
    vl answer;
    fo(i, m)
    {
        ll x = customer[i];
        ll index = upper_bound(price.begin(), price.end(), x) - price.begin();
        if (index == 0)
        {
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(price[index - 1]);
            price.erase(index + price.begin() - 1);
        }
    }
    fo(i, answer.size())
    {
        cout << answer[i];
        br;
    }
    return 0;
}