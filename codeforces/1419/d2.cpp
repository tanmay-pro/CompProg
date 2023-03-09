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
    ll n;
    cin >> n;
    vl es;
    fo(i, n)
    {
        ll x;
        cin >> x;
        es.push_back(x);
    }
    sort(es.begin(), es.end());
    vl b;
    deque<ll> dqSmall;
    deque<ll> dqLarge;
    ll ideal;
    if (n % 2 == 0)
    {
        ideal = n / 2 - 1;
    }
    else
    {
        ideal = n / 2;
    }
    fo(i, ideal)
    {
        dqSmall.push_back(es[i]);
    }
    Fo(i, ideal, n)
    {
        dqLarge.push_back(es[i]);
    }
    sort(dqSmall.begin(), dqSmall.end());
    sort(dqLarge.begin(), dqLarge.end());
    ll x = dqLarge.front();
    dqLarge.pop_front();
    b.push_back(x);
    while (!dqSmall.empty() && !dqLarge.empty())
    {
        ll y = dqSmall.front();
        dqSmall.pop_front();
        b.push_back(y);
        ll x = dqLarge.front();
        dqLarge.pop_front();
        b.push_back(x);
    }
    while (!dqSmall.empty())
    {
        ll x = dqSmall.front();
        dqSmall.pop_front();
        b.push_back(x);
    }
    while (!dqLarge.empty())
    {
        ll x = dqLarge.front();
        dqLarge.pop_front();
        b.push_back(x);
    }
    ll ans = 0;
    Fo(i, 1, b.size())
    {
        if (b[i] < b[i - 1] && b[i] < b[i + 1])
        {
            ans++;
        }
        i++;
        if (i >= n - 1)
            break;
    }
    cout << ans;
    br;
    fo(i, b.size())
    {
        cout << b[i] << " ";
    }
    br;

    return 0;
}