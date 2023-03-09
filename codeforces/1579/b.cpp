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

void rotate(ll l, ll r, vl &a)
{
    deque<ll> dq;
    Fo(i, l, r + 1)
    {
        dq.push_back(a[i]);
    }
    ll elem = dq.back();
    dq.pop_back();
    dq.push_front(elem);
    Fo(i, l, r + 1)
    {
        a[i] = dq.front();
        dq.pop_front();
    }
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
        vl a(n);
        priority_queue<ll, vl, greater<ll>> pq;
        fo(i, n)
        {
            cin >> a[i];
            pq.push(a[i]);
        }
        ll ans = 0;
        vl l, r, d;
        fo(i, n)
        {
            if (is_sorted(a.begin(), a.end()))
            {
                break;
            }
            ll elem = pq.top();
            pq.pop();
            ll ind;
            fo(j, n)
            {
                if (a[j] == elem)
                {
                    ind = j;
                }
            }
            rotate(i, ind, a);
            if (ind != i)
            {
                l.pb(i + 1);
                r.pb(ind + 1);
                d.pb(ind - i);
                ans++;
            }
        }
        cout << ans << endl;
        fo(i, ans)
        {
            cout << l[i] << " " << r[i] << " " << d[i] << endl;
        }
    }
    return 0;
}