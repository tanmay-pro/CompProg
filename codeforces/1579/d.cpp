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
        ll n;
        cin >> n;
        priority_queue<pll, vpl> pq;
        fo(i, n)
        {
            ll x, y;
            x = i + 1;
            cin >> y;
            pq.push({y, x});
        }
        ll ans = 0;
        vpl arr;
        while (!pq.empty())
        {
            pll p1 = pq.top();
            pq.pop();
            if (pq.empty())
                break;
            pll p2 = pq.top();
            pq.pop();
            ll val1 = p1.ff;
            ll val2 = p2.ff;
            val1--;
            val2--;
            if (val2 >= 0)
            {
                arr.push_back({p1.ss, p2.ss});
                ans++;
            }
            ll ind = p1.ss;
            ll ind2 = p2.ss;
            if (val1 > 0)
                pq.push({val1, ind});
            if (val2 > 0)
                pq.push({val2, ind2});
            if (pq.size() == 1)
                break;
        }
        cout << ans << endl;
        fo(i, arr.size())
        {
            cout << arr[i].ff << " " << arr[i].ss << endl;
        }
    }
    return 0;
}